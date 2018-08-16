if [ $# -ne 1 ]
 then
  echo "usage: $0 <class_name>"
  exit 0
fi
name=$1

mkdir $name
mv ${name}.h $name
