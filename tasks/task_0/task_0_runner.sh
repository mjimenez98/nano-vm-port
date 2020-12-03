testRunner() {
    for i in {1..12}
    do
        local filename="T0$i.exe"
        if [ $i -gt 9 ]
        then
            filename="T$i.exe"
        fi

        if [ $i -eq 1 ]
        then
            ../../cmake-build-debug/./nano_vm_port ../../tests/$filename > output.txt
        else
            ../../cmake-build-debug/./nano_vm_port ../../tests/$filename >> output.txt
        fi
    done

    ./aunit output.txt
}

testRunner
