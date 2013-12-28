= 付録: Instagram APIクライアントIDの取得手順

== アプリケーション登録する

Instagram APIへ接続するためのID取得には、開発者ページでアプリ登録が必要です。

@<href>{http://instagram.com/developer/}

//image[developer][開発者ページ]{
//}

Instagramへログインした状態で開発者ページヘアクセスし、アプリケーションを登録しましょう。

//image[register][アプリケーション登録画面]{
//}


入力する内容はだいたいこんな感じです。全て入力しないとエラーになるので、コールバックなど使用しない場合もダミーの値を入力しておく必要があります。

: Application Name
    アプリ名。重複のない任意の名前を入力します。
: Description
    アプリの概要。今回は適当に。
: Website
    アプリのサイトURL。こちらも適当に。
: OAuth redirect_uri
    コールバックURL。適当に。

//image[applications][アプリケーション管理画面]{
//}

登録が完了すると、CLIENT ID, CLIENT SECRETの値が表示されます。