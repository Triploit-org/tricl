# Triploit Client - Nur für Linux

Der Triploit Client kann dazu benutzt werden um Programme aus der Repository der Organisation zu installieren.

**Ich übernehme keinerlei Verantwortung für Schäden die durch die Installation oder Deinstallation eines Programmes mithilfe des Triploit Clients entstehen!**  
**I do not take any responsibility for damage caused by installing or uninstalling a program using the Triploit Client!**


## Client kompilieren
Es reicht ein einfaches

    make all

um den Client zu kompileren.

## Pakete herunterladen

Um ein Paket auszuführen, müssen wir den Client erst kompilieren. Nachdem er kompiliert wurde und somit die Chance auf Bugs oder Fehler verringert wurde, können wir ein Paket herunterladen:

    ./tricl install [Paket]

Lasst uns doch einfach mal die neue Ny++ Version herunterladen:

    ./tricl install ny-6

Damit wird dieses Paket heruntergeladen und in einem extra Ordner gespeichert.

## Ein eigenes Paket erstellen

Um ein eigenes Paket zu erstellen, ist ein GitHub-Account nötig. Auf diesem Account legt man dann eine Repository an, die das Paket repräsentieren wird.

In der Repo muss im Wurzelverzeichnis eine "pkgins.cfg" enthalten sein, damit eine Installation (und nicht nur ein Download) möglich ist. In dieser Datei wird dann ein LOL-Code ähnlicher Befehl geschrieben, damit der Client weiß, was er zu tun hat:

    pls mv test.txt to dir ~/test.txt
    
Das ist soweit der Befehl, der die Datei test.txt in das Verzeichnis ~/ verschiebt. Es ist ungemein wichtig, das angegeben wird, wie die Datei heißt und nicht nur der Ordner, wo die Datei hinverschoben werden soll (also nicht ~/ sondern ~/test.txt). **Denn sonnst wird beim löschen des Paketes der Ordner ~/ gelöscht!**
Um dieses Paket dann mit dem Client herunterzuladen, muss nur ein Argument hinzugefügt werden:

    ./tricl -m <GitHubUser> <Paket>
    
Nehmen wir an, ich habe einen GitHub-Account der `musterman` heißt, auf diesem Account erstelle ich eine Repo `hello-world-cpp`. In dieser Repo ist ein Source Code in C++ für ein Hallo Welt enthalten und eine Binädatei die `Hallo Welt` auf der Konsole ausgibt.
So sieht die Repo aus:
    
    hello-world-cpp
    |
    |-> helloworld.cpp
    --> pkgins.cfg

Die pkgins.cfg:

    pls mv helloworld.cpp to dir ~/helloworld.cpp
    
Hier ist dann der Befehl:

    ./tricl -m musterman hello-world-cpp
    
Dann wird in der Repo `hello-world-cpp` des User `musterman` nach der Config geschaut und sie wird installiert.
