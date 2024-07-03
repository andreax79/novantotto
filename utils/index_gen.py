import html
import os
import sys
import urllib.parse


def list_directory(path: str) -> None:
    files = [x for x in os.listdir(path) if not x.startswith(".") and x != "index.html"]
    files.sort(key=lambda a: a.lower())
    displaypath = html.escape(path, quote=False)
    title = f"Directory listing for {displaypath}"
    print("<!doctype html>")
    print("<html>\n<head>")
    print('<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />')
    print(f"<title>{title}</title>\n</head>")
    print(f"<body>\n<h1>{title}</h1>")
    print("<hr>\n<ul>")
    for name in files:
        fullname = os.path.join(path, name)
        displayname = linkname = name
        # Append / for directories
        if os.path.isdir(fullname):
            displayname = name + "/"
            linkname = name + "/"
        linkname = urllib.parse.quote(linkname, errors="surrogatepass")
        displayname = html.escape(displayname, quote=False)
        print(f'<li><a href="{linkname}">{displayname}</a></li>')
    print("</ul>\n<hr>\n</body>\n</html>\n")


list_directory(sys.argv[1])
