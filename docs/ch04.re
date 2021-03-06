= Herokuへデプロイしてみよう

ここでいったんアプリの作成の手を止めて、作成中のアプリをHerokuへデプロイしてみましょう。
herokuコマンドには、Heroku Toolbeltが必要なので、まだの人はインストールしておいてください。

@<href>{https://toolbelt.heroku.com/}

//image[heroku-toolbelt][heroku toolbelt]{
//}

== herokuアプリを作成する

heroku createコマンドでアプリを作成します。

//emlist{

$ heroku create
Creating dry-everglades-1554... done, stack is cedar
http://dry-everglades-1554.herokuapp.com/ | git@heroku.com:dry-everglades-1554.git
Git remote heroku added
//}


== デプロイする

git pushすることでデプロイすることができます。簡単便利。

//emlist{
$ git push heroku master
Initializing repository, done.
Counting objects: 100, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (87/87), done.
Writing objects: 100% (100/100), 19.49 KiB | 0 bytes/s, done.
Total 100 (delta 21), reused 0 (delta 0)

-----> Ruby app detected
-----> Compiling Ruby/Rails
-----> Using Ruby version: ruby-2.1.0
...
//}


== herokuアプリへ環境変数を設定する

ローカル環境で.envに保存されているInstagram API用の環境変数を、Herokuアプリで有効にする必要があります。
heroku config:addコマンドで環境変数を設定しましょう。

//emlist{

$ heroku config:add INSTAGRAM_CLIENT_ID=[YOUR_CLIENT_ID]
$ heroku config:add INSTAGRAM_CLIENT_SECRET=[YOUR_CLIENT_SECRET]

//}

heroku configコマンドで設定した内容を確認しましょう。

//emlist{

$ heroku config | grep INSTAGRAM
INSTAGRAM_CLIENT_ID:         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
INSTAGRAM_CLIENT_SECRET:     xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//}


== 表示を確認する

heroku open コマンドでサイトの表示を確認してみましょう。ねこまみれなはずです。

//emlist{

$ heroku open

//}

//image[top][トップ画面]{
//}
