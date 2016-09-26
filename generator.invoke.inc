<?php

/**
 * @file
 *
 * This file provides with hook invoke functions.
 */

/**
 * Returns info on a generator.
 *
 * @param null|string $generator
 *   The generator's name.
 *
 * @return array
 */
function generator_generator_get_info($generator = NULL) {
  $hook = 'generator_info';
  $cid  = GENERATOR_CACHE__BUILDER_INFO;
  // Cached since used very often
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast[$hook] = &drupal_static(__FUNCTION__);
  }
  $generator_info = &$drupal_static_fast[$hook];
  if (empty($generator_info)) {
    if ($cache = generator_cache_get($cid)) {
      $generator_info = $cache->data;
    }
    else {
      $data = module_invoke_all($hook);
      drupal_alter($hook, $data);
      $info = array();
      foreach ($data as $key => $values) {

      }

      $generator_info = $info;
      generator_cache_set($cid, $generator_info);
    }
  }

  return isset($generator) ? $generator_info[$generator] : $generator_info;
}

/**
 * Returns info on builder.
 *
 * @param null|string $builder
 *   The builder's name.
 *
 * @return array
 */
function generator_builder_get_info($builder = NULL) {
  $hook = 'builder_info';
  $cid  = GENERATOR_CACHE__BUILDER_INFO;
  // Cached since used very often
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast[$hook] = &drupal_static(__FUNCTION__);
  }
  $builder_info = &$drupal_static_fast[$hook];
  if (empty($builder_info)) {
    if ($cache = generator_cache_get($cid)) {
      $builder_info = $cache->data;
    }
    else {
      $data = module_invoke_all($hook);
      drupal_alter($hook, $data);
      $info = array();
      foreach ($data as $key => $values) {

      }

      $builder_info = $info;
      generator_cache_set($cid, $builder_info);
    }
  }

  return isset($builder) ? $builder_info[$builder] : $builder_info;
}

/**
 * Returns info on a model.
 *
 * @param null|string $model
 *   The model's name.
 *
 * @return array
 */
function generator_model_get_info($model = NULL) {
  $hook = 'model_info';
  $cid  = GENERATOR_CACHE__MODEL_INFO;
  // Cached since used very often
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast[$hook] = &drupal_static(__FUNCTION__);
  }
  $model_info = &$drupal_static_fast[$hook];
  if (empty($model_info)) {
    if ($cache = oop_cache_get($cid)) {
      $model_info = $cache->data;
    }
    else {
      $data = module_invoke_all($hook);
      drupal_alter($hook, $data);
      $info = array();
      foreach ($data as $key => $values) {

      }

      $model_info = $info;
      oop_cache_set($cid, $model_info);
    }
  }

  return isset($model) ? $model_info[$model] : $model_info;
}

/**
 * Returns info on a Ki class.
 *
 * @param null|string $ki
 *   The ki name as was declared in the related hook.
 *
 * @return array
 * @see hook_ki_info().
 */
function generator_ki_get_info($ki = NULL) {
  $hook = 'ki_info';
  $cid  = GENERATOR_CACHE__KI_INFO;
  // Cached since used very often
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast[$hook] = &drupal_static(__FUNCTION__);
  }
  $ki_info = &$drupal_static_fast[$hook];
  if (empty($ki_info)) {
    if ($cache = oop_cache_get($cid)) {
      $ki_info = $cache->data;
    }
    else {
      $data = module_invoke_all($hook);
      drupal_alter($hook, $data);
      $info = array();
      foreach ($data as $key => $values) {

      }

      $ki_info = $info;
      oop_cache_set($cid, $ki_info);
    }
  }

  return isset($ki) ? $ki_info[$ki] : $ki_info;
}