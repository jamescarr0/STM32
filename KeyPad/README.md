openocd -f board/stm32f4discovery.cfg  

arm-none-eabi-gdb build/main.elf  

Monitor reset halt

monitor arm semihosting enable

load

continue

---

-> arm-none-eabi-gdb build/main.elf -ex "target extended-remote localhost:3333" -ex "monitor reset halt" -ex "monitor arm semihosting enable"

(gdb) load
(gdb) continue

---

4x4 Matrix Membrane keypad:
Pin1 - PD3
Pin2 - PD2
Pin3 - PD1
Pin4 - PD0
Pin5 - PB4 
Pin6 - PB5
Pin7 - PB7
Pin8 - PB8
