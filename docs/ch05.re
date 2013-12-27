= Bootstrapで見た目を良くしよう

見た目を良くするため、Bootstrapを組み込みましょう。

@<href>{http://getbootstrap.com/}

//image[bootstrap][Bootstrap]{
//}


== bootstrap-sassをインストールする

Rails + BootstrapのGemはいくつかありますが、今回はbootstrap-sassを使用します。

Gemfileにbootstrap-sassと、ついでにfont-awesome-railsを追加しましょう。

bootstrap3を使いたいので、バージョンを指定します。

//source[/Gemfile]{

...
# css
gem 'bootstrap-sass', '~> 3.0.3.0'
gem 'font-awesome-rails', '~> 4.0.3.0'
...

//}

bundleコマンドでインストールし、スタイルシートとビューを変更します。

//source[/app/assets/stylesheets/application.css.scss]{

@import "bootstrap";
@import "font-awesome";

//}

//source[/app/views/layouts/application.html.erb]{

...
<body>
<div class="container">
  <%= yield %>
</div>
</body>
...

//}


== viewを改良する

ちょっとオシャレっぽくするために、背景画像やサムネイル表示を追加してみましょう。

//source[/app/assets/stylesheets/nyansta.css.sass]{

@import "bootstrap";
@import "font-awesome";
@import "nyansta";

//}

※ /app/assets/images/bg.jpg に適当な画像を設置してください。

//source[/app/assets/stylesheets/nyansta.css.sass]{

body
  background: image-url('bg.jpg') no-repeat center center fixed
  padding: 60px 60px
  -webkit-background-size: cover
  -moz-background-size: cover
  -o-background-size: cover
  background-size: cover

.thumbnail
  background: #fff
  background: rgba(255,255,255,0.9)

//}

//source[/app/views/home/_media.html.erb]{

<div class="col-xs-12 col-sm-6 col-md-4">
  <div class="thumbnail">
    <%= link_to(media.link) do %>
      <%= image_tag(media.images.low_resolution.url, class: 'img-rounded') %>
      <div class="caption">
        <p>
          <i class="fa fa-instagram">&nbsp;</i>
          <%= truncate(media.caption.text, length: 20) if media.caption %>
        </p>
      </div>
    <% end %>
  </div>
</div>
//}

== assetsの静的ファイルの設定を変更する

heroku環境(production環境)でassetsファイルが有効になるよう、静的ファイルの設定をtrueに変更します。

//source[/config/environments/production.rb]{
NyanstaDemo::Application.configure do
  ...
  config.serve_static_assets = true
  ...
end

//}

変更をgitリポジトリへコミットしておきましょう。

//emlist{
$ git add .
$ git commit -m 'Bootstrapで見た目を良くした'
//}

== デプロイする

herokuへデプロイしてみましょう。いい感じにねこまみれてるはず。

//emlist{
$ git push heroku master
$ heroku open
//}


//image[top][ねこにまみれたトップ画面]{
//}

== この章での変更点

ここまでの変更は下記コミットログで確認できます。

@<href>{https://github.com/mochiz/nyansta-demo/commit/8edec1a3}
