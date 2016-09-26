<?php

/**
 * @file
 *
 * This file provides with cache related functions.
 */

/**
 * Cache cid for builder_info.
 */
define('GENERATOR_CACHE__GENERATOR_INFO', 'generator_info');
/**
 * Cache cid for builder_info.
 */
define('GENERATOR_CACHE__BUILDER_INFO', 'builder_info');
/**
 * Cache cid for model_info.
 */
define('GENERATOR_CACHE__MODEL_INFO', 'model_info');
/**
 * Cache cid for ki_info.
 */
define('GENERATOR_CACHE__KI_INFO', 'model_info');

/**
 * Implements hook_admin_menu_cache_info().
 */
function generator_admin_menu_cache_info() {
  $caches[GENERATOR] = array(
    'title'    => t('Generator\'s cache'),
    'callback' => 'generator_cc_all',
  );

  return $caches;
}

/**
 * Implements hook_flush_caches().
 */
function generator_flush_caches() {
  return array(GENERATOR_DB__CACHE);
}

/**
 * Cache data fore generator in cache_generator.
 * Sets the cache in generator cache table.
 *
 * @param string $cid
 *   The cache ID.
 * @param mixed  $data
 *   The data to cache.
 * @param int    $expire
 *   The expiration in seconds.
 */
function generator_cache_set($cid, $data, $expire = CACHE_PERMANENT) {
  generic_cache_set(GENERATOR_DB__CACHE, $cid, $data, $expire);
}

/**
 * Returns cache from cache_generator.
 * Gets the cache from generator cache table.
 *
 * @param $cid
 *   The cache ID.
 *
 * @return null|object
 */
function generator_cache_get($cid) {
  return generic_cache_get(GENERATOR_DB__CACHE, $cid);
}

/**
 * Clear generator cache.
 * Once cleared, related cache IDs are cleared as well.
 *
 * @param string $cid
 *   The generator cache ID.
 *
 * @see hook_cache_info().
 */
function generator_cache_clear($cid) {
  generic_cache_clear(GENERATOR_DB__CACHE, $cid);
}

/**
 * Clear the cache for every generator cache id.
 */
function generator_cc_all() {
  cache_clear_all('*', GENERATOR_DB__CACHE, TRUE);
}

/**
 * Implements hook_cache_info().
 */
function generator_cache_info() {
  $info                                  = array();
  $info[GENERATOR_CACHE__GENERATOR_INFO] = array();
  $info[GENERATOR_CACHE__BUILDER_INFO]   = array();
  $info[GENERATOR_CACHE__MODEL_INFO]     = array();
  $info[GENERATOR_CACHE__KI_INFO]        = array();

  return $info;
}