import os
import glob

path_to_clean = ["cpp"]
file_patterns = ["*.o", "*.exe"]

"""
    This script will delete all files with the extensions specified in file_patterns
"""

class Cleaner:
    def __init__(self) -> None:
        self.total_deleted_files = 0
        self.total_deleted_size = 0

    def delete_file(self, file_path):
        try:
            file_size = os.path.getsize(file_path)
            os.remove(file_path)
            self.total_deleted_files += 1
            self.total_deleted_size += file_size
            print(f"Deleted: {file_path} ({file_size} bytes)")
        except Exception as e:
            print(f"Error deleting {file_path}: {e}")

    def walk_into_folder(self, folder_path):
        # List of subfolders
        subfolders = [f.path for f in os.scandir(folder_path) if f.is_dir()]
        for subfolder in subfolders:
            self.walk_into_folder(subfolder)
        
        # List of files
        for file_pattern in file_patterns:
            files = glob.glob(os.path.join(folder_path, file_pattern))
            for file in files:
                self.delete_file(file)

    def perform_action(self, folder_path):
        self.walk_into_folder(folder_path)
    
    def print(self) -> None:
        print(f"Total files deleted: {self.total_deleted_files}")
        print(f"Total space freed: {self.total_deleted_size} bytes")
        print(f"Total space freed (in KB): {self.total_deleted_size / 1024:.2f} KB")
        print(f"Total space freed (in MB): {self.total_deleted_size / 1024 / 1024:.2f} MB")

if __name__ == "__main__":
    cleaner = Cleaner()
    for path in path_to_clean:
        cleaner.perform_action(path)
    cleaner.print()
    