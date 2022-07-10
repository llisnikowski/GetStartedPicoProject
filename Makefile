compile:
	mkdir -p build && \
	cd build && cmake .. && make -j

clean:
	cd build && rm -r *

upload:
	sudo mkdir -p /mnt/pico 
	sudo mount /dev/sdc1 /mnt/pico &&\
	sudo cp build/main.uf2 /mnt/pico
	sudo sync
	sudo umount /mnt/pico

openSerialPort:
	minicom -b 115200 -o -D /dev/ttyUSB0

findPort:
	sudo dmesg | tail

.SILENT:
