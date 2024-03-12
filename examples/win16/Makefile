novantotto_home = ../..
sources = *.c $(novantotto_home)/*.c \

.PHONY: build
build: copy
	emcc $(sources) -o win16.js \
		$(CFLAGS) \
		-I $(novantotto_home) \
		-s GLOBAL_BASE=66536 \
		-s ASYNCIFY \
		-s ASSERTIONS=2 \
		-s SAFE_HEAP=1 \
		-s STACK_OVERFLOW_CHECK=2 \
		-s DEMANGLE_SUPPORT=1 \
        -s 'ASYNCIFY_IMPORTS=["emscripten_asm_const_int"]' \
        -s 'EXPORTED_RUNTIME_METHODS=["ccall", "setValue"]' \
        -s 'EXPORTED_FUNCTIONS=["_main", "_GetDlgItem", "_PostMessage", "_PrintMessages", "_AllocateControl", "_GetTickCount", "_WinMainStartup"]'

.PHONY: format
format:
	clang-format -i *.h *.c

.PHONY: rc
rc: copy
	@RESOURCES_DIR="./resources/" $(novantotto_home)/utils/rc.sh Resource.rc

.PHONY: copy
copy:
	@mkdir -p resources/bitmaps/novantotto
	@cp -r $(novantotto_home)/bitmaps/* resources/bitmaps/novantotto
	@mkdir -p resources/icons/novantotto
	@cp -r $(novantotto_home)/icons/* resources/icons/novantotto
	@mkdir -p resources/css
	@cp -r $(novantotto_home)/css/* resources/css
	@mkdir -p resources/js
	@cp -r $(novantotto_home)/js/* resources/js

.PHONY: clean
clean:
	@rm -rf resources
