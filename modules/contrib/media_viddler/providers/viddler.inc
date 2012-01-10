<?php

/**
 *  This is the main URL for your provider.
 */
define('EMVIDEO_VIDDLER_MAIN_URL', 'http://www.viddler.com/');

/**
 *  This is the URL to the API of your provider, if this exists.
 */
define('EMVIDEO_VIDDLER_API_URL', 'http://developers.viddler.com/documentation/');

/**
 *  This is the default color for the Viddler player 
 */
define('EMVIDEO_VIDDLER_COLOR_DEFAULT', '#01AAEA');

/**
 *  This is the default player for the Viddler player 
 */
 
define('EMVIDEO_VIDDLER_PLAYER', 'http://www.viddler.com/player/key');

/**
 *  This defines the version of the content data array that we serialize
 *  in emvideo_viddler_data(). If we change the expected keys of that array,
 *  we must increment this value, which will allow older content to be updated
 *  to the new version automatically.
 */
define('EMVIDEO_VIDDLER_DATA_VERSION', 1);

/**
 * hook emvideo_PROVIDER_info
 * This returns information relevant to a specific 3rd party video provider.
 *
 * @return
 *   A keyed array of strings requested by various admin and other forms.
 *    'provider' => The machine name of the provider. This must be the same as
 *      the base name of this filename, before the .inc extension.
 *    'name' => The translated name of the provider.
 *    'url' => The url to the main page for the provider.
 *    'settings_description' => A description of the provider that will be
 *      posted in the admin settings form.
 *    'supported_features' => An array of rows describing the state of certain
 *      supported features by the provider. These will be rendered in a table,
 *      with the columns being 'Feature', 'Supported', 'Notes'. In general,
 *      the 'Feature' column will give the name of the feature, 'Supported'
 *      will be Yes or No, and 'Notes' will give an optional description or
 *      caveats to the feature.
 */
function emvideo_viddler_info() {
  $features = array(
    array(t('Autoplay'), t('Yes'), ''),
    array(t('Thumbnails'), t('Yes'), ''),
    array(t('Full screen mode'), t('Yes'), t('You may customize the player to enable or disable full screen playback. Full screen mode is enabled by default.')),
    array(t('Custom player color'), t('No'), ''),
  );
  return array(
    'provider' => 'viddler',
    'name' => t('Viddler'),
    'url' => EMVIDEO_VIDDLER_MAIN_URL,
    'settings_description' => t('These settings specifically affect videos displayed from !viddler. You can also read more about its !api.', array('!viddler' => l(t('viddler.com'), EMVIDEO_VIDDLER_MAIN_URL), '!api' => l(t("developer's API"), EMVIDEO_VIDDLER_API_URL))),
    'supported_features' => $features,
  );
}

/**
 *  hook emvideo_PROVIDER_settings
 *  This should return a subform to be added to the emvideo_settings() admin
 *  settings page.
 *
 *  Note that a form field set will already be provided at $form['viddler'],
 *  so if you want specific provider settings within that field set, you should
 *  add the elements to that form array element.
 */
function emvideo_viddler_settings() {
  $form['viddler']['player'] = array(
    '#type' => 'fieldset',
    '#title' => t('Embedded video player options'),
    '#description' => t('Styling and playback options for the embedded '.
      'player.'),
    '#collapsible' => true,
    '#collapsed' => true,
  );
  $form['viddler']['player']['color'] = array(
    '#type' => 'fieldset',
    '#title' => t('Embedded video player color'),
    '#description' => t('If allowed, this color, in hexidecimal form (#RRGGBB), will be used to change the skin of the Viddler player.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['viddler']['player']['color']['emvideo_viddler_color_override'] = array(
    '#type' => 'checkbox',
    '#title' => t('Override player color'),
    '#default_value' => variable_get('emvideo_viddler_color_override', FALSE),
  );
  $form['viddler']['player']['color']['emvideo_viddler_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Color'),
    '#default_value' => variable_get('emvideo_viddler_color', EMVIDEO_VIDDLER_COLOR_DEFAULT),
  );
  $form['viddler']['player']['emvideo_viddler_full_screen'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow fullscreen'),
  '#default_value' => variable_get('emvideo_viddler_full_screen', 1),
  '#description' => t('Allow users to view video using the entire computer screen.'),
  );
  $form['viddler']['player']['emvideo_viddler_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Viddler API Key'),
    '#default_value' => variable_get('emvideo_viddler_api_key', ''),
  );

  return $form;
}

/**
 *  hook emvideo_PROVIDER_extract
 *
 *  This is called to extract the video code from a pasted URL or embed code.
 *
 *  We'll be passed a URL or the embed code from a video when an editor pastes
 *  that in the field's textfield. We'll need to either pass back an array of
 *  regex expressions to match, or do the matching ourselves and return the
 *  resulting video code.
 *
 *  @param $parse
 *    An optional string with the pasted URL or embed code.
 *  @return
 *    Either an array of regex expressions to be tested, or a string with the
 *    video code to be used. If the hook tests the code itself, it should
 *    return either the string of the video code (if matched), or an empty
 *    array. Otherwise, the calling function will handle testing the embed code
 *    against each regex string in the returned array.
 */
function emvideo_viddler_extract($parse = '') {
 
  return array(
    '@http://www\.viddler\.com/player/(\w*)/@i',
    '@http://www\.viddler\.com/simple/(\w*)/@i',
    '@www\.viddler\.com/([^\"\&]+)@i',
  );
}

/**
 *  hook emvideo_PROVIDER_data
 *
 *  Provides an array to be serialised and made available with $item elsewhere.
 *
 *  This data can be used to store any extraneous information available
 *  specifically to the viddler provider.
 */
function emvideo_viddler_data($field, $item) {
  // Initialize the data array.
  $data = array();
  $data =  emfield_request_xml('viddler', 'http://lab.viddler.com/services/oembed/?url=http%3A//www.viddler.com/'. $item['value'], array('type' => 'simple', 'format' => 'xml'), TRUE, FALSE, $item['value']);
  $data['emvideo_viddler_version'] = EMVIDEO_VIDDLER_DATA_VERSION;
  $data['emvideo_viddler_thumbnail'] = $data['OEMBED']['THUMBNAIL_URL'][0];
  // This stores a URL to the video's thumbnail.

  return $data;
}

/**
 *  hook emvideo_PROVIDER_rss
 *
 *  This attaches a file to an RSS feed.
 */
function emvideo_viddler_rss($item, $teaser = NULL) {
}

/**
 * hook emvideo_PROVIDER_embedded_link($video_code)
 * returns a link to view the video at the provider's site.
 *  @param $video_code
 *    The string containing the audio code.
 *  @return
 *    A string containing the URL to view the video at the original provider's site.
 */
function emvideo_viddler_embedded_link($video_code) {
  return 'http://www.viddler.com/'. $video_code;
}

/**
 * The embedded flash displaying the viddler video.
 */
function theme_emvideo_viddler_flash($item, $width, $height, $autoplay) {
  $output = '';
  if ($item['embed'])  {
    $embedurl = $item['data']['OEMBED']['HTML']['clsid:D27CDB6E-AE6D-11cf-96B8-444553540000']['PARAM'][1]['VALUE'];
    $fullscreen = variable_get('emvideo_viddler_full_screen', 1);
    $show_portrait = $on_screen_info['portrait'] ? 1 : 0;
    $output  = '<object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" type="application/x-shockwave-flash" width="'. $width .'" height="'. $height .'" id="viddler_'. $embedurl .'"">';
    $output .= '<embed src="' . $embedurl .'" width="545" height="349" data="'. $player .'" type="application/x-shockwave-flash" allowScriptAccess="always" flashvars="autoplay=t" allowFullScreen="' . ($fullscreen ? 'true' : 'false') . '" name="viddler_" wmode="transparent"></embed>';
    $output .= '<param name="wmode" value="transparent" />';
    $output .= '<param name="allowfullscreen" value="'. ($fullscreen ? 'true' : 'false') .'" />';
    $output .= '<param name="flashvars" value="autoplay=t" />';
    $output .= '<param name="movie" value="'. $embedurl .'" /></object>';
  }
  
  return $output;
}

/**
 * hook emvideo_PROVIDER_thumbnail
 * Returns the external url for a thumbnail of a specific video.
 *  @param $field
 *    The field of the requesting node.
 *  @param $item
 *    The actual content of the field from the requesting node.
 *  @return
 *    A URL pointing to the thumbnail.
 */
function emvideo_viddler_thumbnail($field, $item, $formatter, $node, $width, $height) {
  return $item['data']['emvideo_viddler_thumbnail'] ;
}

/**
 *  hook emvideo_PROVIDER_video
 *  This actually displays the full/normal-sized video we want, usually on the
 *  default page view.
 *  @param $embed
 *    The video code for the video to embed.
 *  @param $width
 *    The width to display the video.
 *  @param $height
 *    The height to display the video.
 *  @param $field
 *    The field info from the requesting node.
 *  @param $item
 *    The actual content from the field.
 *  @return
 *    The html of the embedded video.
 */
function emvideo_viddler_video($embed, $width, $height, $field, $item, &$node, $autoplay) {
  $output = theme('emvideo_viddler_flash', $item, $width, $height, $autoplay);
  return $output;
}

/**
 *  hook emvideo_PROVIDER_video
 *
 *  This actually displays the preview-sized video we want, commonly for the
 *  teaser.
 *  @param $embed
 *    The video code for the video to embed.
 *  @param $width
 *    The width to display the video.
 *  @param $height
 *    The height to display the video.
 *  @param $field
 *    The field info from the requesting node.
 *  @param $item
 *    The actual content from the field.
 *  @return
 *    The html of the embedded video.
 */
function emvideo_viddler_preview($embed, $width, $height, $field, $item, &$node, $autoplay) {
  $output = theme('emvideo_viddler_flash', $item, $width, $height, $autoplay);
  return $output;
}

/**
 *  Implementation of hook_emfield_subtheme.
 *  This returns any theme functions defined by this provider.
 */
function emvideo_viddler_emfield_subtheme() {
    $themes = array(
        'emvideo_viddler_flash'  => array(
            'arguments' => array('item' => NULL, 'width' => NULL, 'height' => NULL, 'autoplay' => NULL),
            'file' => 'providers/viddler.inc',
            'path' => drupal_get_path('module', 'media_viddler'),
        )
    );
    return $themes;
}
/**
 * Converts the default color of the player 
 */
function emvideo_viddler_convert_color($color = NULL) {
  if ($color{0} == '#') {
    return substr($color, 1);
  }
  return $color;
}