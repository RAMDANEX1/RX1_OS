#pragma once

#include <cstdint>
#include <cstddef>

namespace kernel::filesystem {

// Inode structure
struct Inode {
    uint32_t inode_number;
    uint16_t mode;
    uint32_t size;
    uint32_t owner;
    uint32_t block[12];
    uint32_t indirect_block;
};

// Directory entry
struct DirectoryEntry {
    uint32_t inode_number;
    uint16_t record_length;
    uint8_t name_length;
    uint8_t file_type;
    char name[256];
};

class VirtualFileSystem {
public:
    bool mount(const char* device, const char* mount_point);
    bool umount(const char* mount_point);
    
    // File operations
    int open(const char* path, int flags);
    void close(int fd);
    ssize_t read(int fd, void* buffer, size_t count);
    ssize_t write(int fd, const void* buffer, size_t count);
    
private:
    // TODO: Implémentation VFS
};

} // namespace kernel::filesystem
