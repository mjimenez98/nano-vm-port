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
      ./nano_vm_port ../../tests/$filename > output.txt
    else
      ./nano_vm_port ../../tests/$filename >> output.txt
    fi
  done

  ./aunit.exe output.txt
}

if [[ $1 == "compile" ]]
then
  gcc -Wall ../task_0/aunit.c -o aunit.exe
fi

testRunner
