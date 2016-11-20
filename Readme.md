# Triploit Client - Nur für Linux

Der Triploit Client kann dazu benutzt werden um Programme aus der Repository der Organisation zu installieren.

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
