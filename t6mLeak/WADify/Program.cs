using Ionic.Zlib;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace wadifytool
{
    class Program
    {
        public struct WADHeader
        {
            public UInt32 magic;
            public UInt32 timestamp;
            public UInt32 numEntries;
            public UInt32 ffotdVersion;
        }
        public struct WADEntry
        {
            public string name;
            public UInt32 compressedSize;
            public UInt32 size;
            public UInt32 offset;
           
            // these are not part of T5's WADEntry struct but fuck it
            public byte[] compressedBuf;
        }
        public struct WAD
        {
            public WADHeader header;
            public List<WADEntry> entries;
        }
        static UInt32 SwapUInt32(UInt32 v)
        {
            return (uint)((((((v & 0xff) << 8) | ((v >> 8) & 0xff))) & 0xffff) << 0x10) | (((((v >> 0x10 & 0xff) << 8) | (((v >> 0x10) >> 8) & 0xff))) & 0xffff);
        }
        static List<WADEntry> ProcessOnlineWAD(byte[] bytes)
        {
            MemoryStream stream = new MemoryStream(bytes);
            BinaryReader reader = new BinaryReader(stream);

            WADHeader header = new WADHeader();

            header.magic = reader.ReadUInt32();
            header.timestamp = reader.ReadUInt32();
            header.numEntries = reader.ReadUInt32();
            header.ffotdVersion = reader.ReadUInt32();

            if(header.magic != 0x543377AB)
            {
                Console.WriteLine("Invalid or unsupported file.");
                return null;
            }

            Console.WriteLine("FFOTD version: {0}, entries: {1}", 
                header.ffotdVersion, header.numEntries);

            List<WADEntry> entries = new List<WADEntry>();

            for(int i = 0; i < header.numEntries; i++)
            {
                byte[] entryData = new byte[44]; //size of WADEntry
                int index = (16+(44*i));
                Array.Copy(bytes, index, entryData, 0, entryData.Length);

                MemoryStream stream2 = new MemoryStream(entryData);
                BinaryReader reader2 = new BinaryReader(stream2);

                WADEntry entry = new WADEntry();

                byte[] entryNameBytes = reader2.ReadBytes(32);

                entry.name = Encoding.ASCII.GetString(entryNameBytes).Trim('\0');

                entry.compressedSize    = SwapUInt32(reader2.ReadUInt32());
                entry.size              = SwapUInt32(reader2.ReadUInt32());
                entry.offset            = SwapUInt32(reader2.ReadUInt32());
                entry.compressedBuf     = new byte[entry.compressedSize];

                entries.Add(entry);
            }

            return entries;
        }
        static WAD WriteOnlineWAD(string[] filenames)
        {
            WADHeader header = new WADHeader();

            header.magic = 0x543377AB;
            header.timestamp = 13371337;
            header.numEntries = (uint)filenames.Length;
            header.ffotdVersion = 0;

            List<WADEntry> entries = new List<WADEntry>();

            uint offset = 16 + (header.numEntries * 44);

            foreach (string name in filenames)
            {
                string[] nameA = name.Split('\\');
                string name2 = nameA[nameA.Length - 1];

                Console.WriteLine("Compressing " + name2 + "...");

                WADEntry entry = new WADEntry();
                byte[] decompressedBuf = File.ReadAllBytes(name);
                byte[] compressedBuf = ZlibStream.CompressBuffer(decompressedBuf);

                entry.name = name2;
                entry.compressedBuf = compressedBuf;
                entry.compressedSize = (uint)compressedBuf.Length;
                entry.offset = offset;
                entry.size = (uint)decompressedBuf.Length;

                offset += entry.compressedSize;
                entries.Add(entry);
            }

            WAD wad = new WAD();
            wad.header = header;
            wad.entries = entries;

            return wad;
        }
        static void InitCompress(string safeFilename)
        {
            string[] filenameA = safeFilename.Split('\\');
            string filename = filenameA[filenameA.Length - 1] + ".wad";
            string[] entryFilenames = Directory.GetFiles(safeFilename);
           
            WAD wadFile = WriteOnlineWAD(entryFilenames);

            MemoryStream stream = new MemoryStream();
            BinaryWriter writer = new BinaryWriter(stream);

            writer.Write(wadFile.header.magic);
            writer.Write(wadFile.header.timestamp);
            writer.Write(wadFile.header.numEntries);
            writer.Write(wadFile.header.ffotdVersion);

            foreach(WADEntry entry in wadFile.entries)
            {
                byte[] nameBytes = Encoding.ASCII.GetBytes(entry.name);
                writer.Write(nameBytes);
                for (int i = 0; i < (32 - entry.name.Length); i++)
                    writer.Write((byte)0);

                writer.Write(SwapUInt32(entry.compressedSize));
                writer.Write(SwapUInt32(entry.size));
                writer.Write(SwapUInt32(entry.offset));
            }

            foreach (WADEntry entry in wadFile.entries)
                writer.Write(entry.compressedBuf);

            File.WriteAllBytes(filename, stream.ToArray());
        }
        static void InitDecompress(string safeFilename)
        {
            // Odd way to get the filename I came up with
            string[] filenameA = safeFilename.Split('\\');
            string filename = filenameA[filenameA.Length - 1];
            string filename2 = filename.Split('.')[0]; //get rid of the extension

            Console.WriteLine("Preparing to decompress " + filename + "...");
            byte[] bytes = File.ReadAllBytes(safeFilename);

            List<WADEntry> entries = ProcessOnlineWAD(bytes);

            if (entries != null)
            {
                Directory.CreateDirectory(@".\\" + filename2 + "\\");

                foreach (WADEntry entry in entries)
                {
                    Console.WriteLine("Decompressing " + entry.name + "...");

                    Array.Copy(bytes, entry.offset, entry.compressedBuf, 0, entry.compressedSize);

                    // Decompress and write the file
                    byte[] uncompressed = ZlibStream.UncompressBuffer(entry.compressedBuf);
                    File.WriteAllBytes(@".\\" + filename2 + "\\" + entry.name, uncompressed);
                }
            }   
        }
        static void Main(string[] args)
        {
            // Detect if our argument is a file or folder (so we can just drag 'n' drop it)
            // if it's a file, then decompress it
            // if it's a folder, then compress it

            if(args.Length == 1)
            {
                FileAttributes attr = File.GetAttributes(args[0]);

                if ((attr & FileAttributes.Directory) == FileAttributes.Directory)
                    InitCompress(args[0]);
                else
                    InitDecompress(args[0]);
            }
            
            //Console.ReadLine();
        }
    }
}