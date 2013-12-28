= 写真を一覧表示しよう

それではRailsっぽくコントローラーとビューを作成してみましょう。

== ホームコントローラーを作成する

rails generate コマンドで、写真を表示するためのコントローラーとビューを作成しましょう。

//emlist{

$ bundle exec rails g controller home index
      create  app/controllers/home_controller.rb
       route  get "home/index"
      invoke  erb
      create    app/views/home
      create    app/views/home/index.html.erb
      invoke  rspec
      create    spec/controllers/home_controller_spec.rb

//}


== ルーティングを更新する

作成したコントローラーがトップ画面に表示されるよう、ルーティングを次のように更新します。

//source[/routes.rb]{

NyanstaDemo::Application.routes.draw do
  root 'home#index'
end


//}

Railsアプリを再起動して、http://localhost:3000 にアクセスして、Home#indexが表示されることを確認しましょう。

//image[home01][ホーム画面]{
//}


== 写真一覧を表示する

画像を表示するため、コントローラーとビューを次のように変更します。

//source[/app/controllers/home_controller.rb]{

class HomeController < ApplicationController
  def index
    @medias = Instagram.tag_recent_media(URI.encode('猫'))
  end
end

//}


//source[/app/views/home/index.html.erb]{

<%= render partial: 'media', collection: @medias %>

//}

//source[/app/views/home/_media.html.erb]{

<%= image_tag(media.images.low_resolution.url) %>

//}

ホーム画面を更新してみましょう。可愛い猫の写真でいっぱいになっているはずです。

//image[home02][ホーム画面]{
//}

最後に変更をgitリポジトリへコミットしておきましょう。

//emlist{
$ git add .
$ git commit -m '写真を一覧表示できるようにした'
//}

== この章での変更点

ここまでの変更は下記コミットログで確認できます。

@<href>{https://github.com/mochiz/nyansta-demo/commit/7f88713e}
