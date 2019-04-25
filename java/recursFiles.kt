    fun sendFiles(dir: Path) {
        recurs(dir).count()
        files.forEach { println(it) }
    }

    fun recurs(dir: Path): Stream<Any> {



        return Files.list(dir).map {
            if (Files.isDirectory(it)) sendFiles(it)
            else files.add(it)
        }
    }