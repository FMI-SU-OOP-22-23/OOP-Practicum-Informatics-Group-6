#include <iostream>
#include <cassert>

struct FlagSet
{
    bool read: 1;
    bool write: 1;
    bool execute: 1;
};

struct FilePermissions
{
    FlagSet owner;
    FlagSet group;
    FlagSet others;
};

const std::size_t PERMISSIONS_LENGTH = 9;

void init(FilePermissions& filePermissions, const char* permissions);

void fillFlagSet(FlagSet& flagSet, const char* permissions);

void printFlagSet(const FlagSet& flagSet);

void printFilePermissions(const FilePermissions& filePermissions);

int main ()
{
    char permissions[PERMISSIONS_LENGTH + 1];
    std::cin >> permissions;

    FilePermissions filePermissions;
    init(filePermissions, permissions);

    printFilePermissions(filePermissions);

    return 0;
}

void init(FilePermissions& filePermissions, const char* permissions)
{
    assert(permissions);

    fillFlagSet(filePermissions.owner, permissions);
    fillFlagSet(filePermissions.group, permissions + 3);
    fillFlagSet(filePermissions.others, permissions + 6);
}

void fillFlagSet(FlagSet& flagSet, const char* permissions)
{
    flagSet.read = permissions[0] == 'r';
    flagSet.write = permissions[1] == 'w';
    flagSet.execute = permissions[2] == 'x';
}

void printFlagSet(const FlagSet& flagSet)
{
    std::cout << flagSet.read << flagSet.write << flagSet.execute << std::endl;
}

void printFilePermissions(const FilePermissions& filePermissions)
{
    std::cout << "Owner permissions: ";
    printFlagSet(filePermissions.owner);
    std::cout << "Group permissions: ";
    printFlagSet(filePermissions.group);
    std::cout << "Others permissions: ";
    printFlagSet(filePermissions.others);
}