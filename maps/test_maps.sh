#!/bin/bash

EXEC=./../so_long
MAP_DIR=test_maps

echo "🧪 Lancement des tests de maps..."
echo

for map in $MAP_DIR/*.ber; do
    echo "-----------------------------------------"
    echo "📄 Test de la map : $map"
    $EXEC "$map"
    RET=$?
    if [ $RET -ne 0 ]; then
        echo "❌ Le programme a quitté avec code $RET"
    else
        echo "✅ Terminé avec succès"
    fi
    echo
done
