= Instagram の画像を一覧表示しよう

//source[/app/views/home/index.html.erb]{

<% @medias.each do |media| %>
  <%= image_tag(media.images.low_resolution.url) %>
<% end %>

//}

//image[home][ホーム画面]{
//}
