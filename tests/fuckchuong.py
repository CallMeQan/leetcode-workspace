import time
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

URL = "http://103.145.63.220:3000/problem_add"
PATH = "D:\\Users\\Downloads"
PROBLEM_ID = ""
LOC = "D:\\Users\\Desktop\\dm chuong"

class DownloadFolderHandler(FileSystemEventHandler):
    def on_created(self, event):
        print(f"Created: {event.src_path}")


if __name__ == "__main__":
    event_handler = DownloadFolderHandler()
    observer = Observer()
    observer.schedule(event_handler, PATH, recursive=False)
    observer.start()
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()
    observer.join()