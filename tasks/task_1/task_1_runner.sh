testRunner() {
  for i in {1..12}
  do
    local filename="T0$i.exe"
    if [ $i -gt 9 ]
    then
      filename="T$i.exe"
    fi

    ./nano_vm_port ../../tests/$filename
  done

  ../task_0/aunit.exe ../task_0/output.txt
}

testRunner
