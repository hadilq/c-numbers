{ pkgs ? import <nixpkgs> {
    #config = { replaceStdenv = ({ pkgs }: pkgs.clangStdenv); };
  }
}:
let
  libc = pkgs.lib.getDev pkgs.stdenv.cc.libc;
  libclang = pkgs.lib.getDev pkgs.clang;
in
pkgs.mkShell {
  name = "c-numbers";

  nativeBuildInputs = with pkgs; [
    git
    cmake
    clang
    clang-tools
  ];

  LANG = "C.UTF-8";
  LC_ALL = "C.UTF-8";

  DOCKER_BUILDKIT = "1";

  shellHook = ''
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${with pkgs; lib.makeSearchPath "lib" [
      clang
    ]}
    export LIBRARY_PATH=$LIBRARY_PATH:${pkgs.clang}/lib
    export libc_includes="${libc}/include"

    cat <<EOF > .clangd
    CompileFlags:
      Add:
        - -I${libc}/include
        - -I${libclang}/resource-root/include
        - -I${./.}/src
    EOF
  '';
}
