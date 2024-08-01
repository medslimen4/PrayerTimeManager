#ifndef STORAGEMANAGMENT_HPP
#define STORAGEMANAGMENT_HPP


#include "..\Domaine\Services\IFile\Ifile.hpp"
class StorageManagment {
private:
 IFile* file;
public:
StorageManagment(IFile* file) : file(file) {}

};

#endif // STOCKAGEMANAGEMENT_HPP
