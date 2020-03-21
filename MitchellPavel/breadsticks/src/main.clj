(ns main
  (:gen-class)
  (:require
   [clojure.java.io :as io]
   [clojure.string :as str]))

(defn b9s
  "returns the sum of a number and the number after breadsticks"
  [sum line]
  (let [parsed (re-matches #"breadsticks (.*)" line)]
   (cond
    (some? parsed) (+ sum (Integer. (last parsed)))
    :else sum)))

(defn -main [filePath]
  (with-open [rdr (io/reader filePath)]
    (println (reduce b9s 0 (line-seq rdr)))))