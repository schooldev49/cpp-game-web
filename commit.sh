function git_sparse_checkout {
    local url=$1
    # directory where the repository will be downloaded, e.g.: ./build/sources
    local dir=$2
    local prj=$3
    local tag=$4
    [[ ( -z "$url" ) || ( -z "$dir" ) || ( -z "$prj" ) || ( -z "$tag" ) ]] && \
        echo "ERROR: git_sparse_checkout: invalid arguments" && \
        return 1
    shift; shift; shift; shift

    # Note: any remaining arguments after these above are considered as a
    # list of files or directories to be downloaded.
    
    cd ..
    [ ! -d "cpp-game-web" ] && mkdir cpp-game-web
    cd cpp-game-web
    git init

        git config core.sparseCheckout true
        local path="" # local scope
        for path in $* ;do
            echo "${path}" >> .git/info/sparse-checkout
        done
        git remote add origin ${url}
    
        git fetch --depth=1 origin ${tag}
        git checkout ${tag}

    
}

 url=https://github.com/schooldev49/Cpp-game
  dir=$(pwd)/sources
  prj=bash-scripts
  tag=main
  git_sparse_checkout $url $dir $prj $tag "test/*"
