/**
 * @fileoverview Suggestion Big Image V1 layout javascript.
 */

// Lazy initialization of ad.
function ensureInit() {
  if (!window.theAd) {
    theAd = new Ad();
  }
}

function onAdData(adData) {
  ensureInit();
  processAdData(adData);
}

var Ad = function() {
  // Any loading layout action should be done here.
  loadTemplateContainer([
    {
      type: 'click-url-area',
      layout_id: 'adContent'
    },
    {
      type: 'image',
      layout_id: 'product-image',
      template_id: 'product1MCImage'
    },
    {
      type: 'text',
      layout_id: 'headline',
      template_id: 'text1TFText',
      template_color_id: 'text1TFTextColor'
    },
    {
      type: 'text',
      layout_id: 'description',
      template_id: 'text2TFText',
      template_color_id: 'text2TFTextColor'
    },
    {
      type: 'text',
      layout_id: 'button-text',
      template_id: 'clickTFText',
      template_color_id: 'clickTFTextColor',
      origin_offset_x: -3,
      origin_offset_y: -3
    },
    {
      type: 'background',
      layout_id: 'button',
      template_color_ids: ['button1MCColor']
    },
    {
      type: 'background',
      layout_id: 'background',
      template_color_ids: ['back1MCColor1']
    },
    {
      type: 'custom-text',
      template_id: 'CUSTOM_TEXT_0_'
    },
    {
      type: 'custom-text',
      template_id: 'CUSTOM_TEXT_1_'
    },
    {
      type: 'custom-text',
      template_id: 'CUSTOM_TEXT_2_'
    },
    {
      type: 'custom-text',
      template_id: 'CUSTOM_TEXT_3_'
    },
    {
      type: 'custom-text',
      template_id: 'CUSTOM_TEXT_4_'
    },
    {
      type: 'custom-image',
      template_id: 'CUSTOM_IMAGE_0_'
    },
    {
      type: 'custom-image',
      template_id: 'CUSTOM_IMAGE_1_'
    },
    {
      type: 'custom-image',
      template_id: 'CUSTOM_IMAGE_2_'
    }
  ]);
};
