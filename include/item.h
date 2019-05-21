/*
item.h

Every game object is defined by an Item.

*/
#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>



// 
typedef struct {
    uint16_t itemID;
} Item;



// 
typedef struct {
  char *name;
  uint8_t fuel;
  uint16_t combustion_refuse;
  bool (*attack)(int64_t, int64_t, uint8_t); // x, z, face_id
  bool (*use)(int64_t, int64_t, uint8_t);    // x, z, face_id
} ItemProperty;



// Global Item IDs
const ItemProperty itemProperties[] = {
    {"air", 0, 0, NULL, NULL},
    {"stone", 0, 0, NULL, NULL},
    {"stone_slab", 0, 0, NULL, NULL},
    {"stone_stairs", 0, 0, NULL, NULL},
    {"smooth_stone", 0, 0, NULL, NULL},
    {"smooth_stone_slab", 0, 0, NULL, NULL},
    {"smooth_stone_stairs", 0, 0, NULL, NULL},
    {"stone_bricks", 0, 0, NULL, NULL},
    {"stone_brick_slab", 0, 0, NULL, NULL},
    {"stone_brick_stairs", 0, 0, NULL, NULL},
    {"stone_brick_wall", 0, 0, NULL, NULL},
    {"chiseled_stone_bricks", 0, 0, NULL, NULL},
    {"cracked_stone_bricks", 0, 0, NULL, NULL},
    {"cracked_stone_brick_slab", 0, 0, NULL, NULL},
    {"cracked_stone_brick_stairs", 0, 0, NULL, NULL},
    {"cracked_stone_brick_wall", 0, 0, NULL, NULL},
    {"mossy_stone_bricks", 0, 0, NULL, NULL},
    {"mossy_stone_brick_slab", 0, 0, NULL, NULL},
    {"mossy_stone_brick_stairs", 0, 0, NULL, NULL},
    {"mossy_stone_brick_wall", 0, 0, NULL, NULL},
    {"cobblestone", 0, 0, NULL, NULL},
    {"cobblestone_slab", 0, 0, NULL, NULL},
    {"cobblestone_stairs", 0, 0, NULL, NULL},
    {"cobblestone_wall", 0, 0, NULL, NULL},
    {"mossy_cobblestone", 0, 0, NULL, NULL},
    {"mossy_cobblestone_slab", 0, 0, NULL, NULL},
    {"mossy_cobblestone_stairs", 0, 0, NULL, NULL},
    {"mossy_cobblestone_wall", 0, 0, NULL, NULL},
    {"andesite", 0, 0, NULL, NULL},
    {"andesite_slab", 0, 0, NULL, NULL},
    {"andesite_stairs", 0, 0, NULL, NULL},
    {"andesite_wall", 0, 0, NULL, NULL},
    {"polished_andesite", 0, 0, NULL, NULL},
    {"polished_andesite_slab", 0, 0, NULL, NULL},
    {"polished_andesite_stairs", 0, 0, NULL, NULL},
    {"diorite", 0, 0, NULL, NULL},
    {"diorite_slab", 0, 0, NULL, NULL},
    {"diorite_stairs", 0, 0, NULL, NULL},
    {"diorite_wall", 0, 0, NULL, NULL},
    {"polished_diorite", 0, 0, NULL, NULL},
    {"polished_diorite_slab", 0, 0, NULL, NULL},
    {"polished_diorite_stairs", 0, 0, NULL, NULL},
    {"granite", 0, 0, NULL, NULL},
    {"granite_slab", 0, 0, NULL, NULL},
    {"granite_stairs", 0, 0, NULL, NULL},
    {"granite_wall", 0, 0, NULL, NULL},
    {"polished_granite", 0, 0, NULL, NULL},
    {"polished_granite_slab", 0, 0, NULL, NULL},
    {"polished_granite_stairs", 0, 0, NULL, NULL},
    {"marble", 0, 0, NULL, NULL},
    {"marble_slab", 0, 0, NULL, NULL},
    {"marble_stairs", 0, 0, NULL, NULL},
    {"marble_wall", 0, 0, NULL, NULL},
    {"marble_pillar", 0, 0, NULL, NULL},
    {"chiseled_marble", 0, 0, NULL, NULL},
    {"polished_marble", 0, 0, NULL, NULL},
    {"polished_marble_slab", 0, 0, NULL, NULL},
    {"polished_marble_stairs", 0, 0, NULL, NULL},
    {"flagstone", 0, 0, NULL, NULL},
    {"flagstone_slab", 0, 0, NULL, NULL},
    {"flagstone_stairs", 0, 0, NULL, NULL},
    {"flagstone_wall", 0, 0, NULL, NULL},
    {"limestone", 0, 0, NULL, NULL},
    {"crushed_limestone", 0, 0, NULL, NULL},
    {"end_stone", 0, 0, NULL, NULL},
    {"end_stone_bricks", 0, 0, NULL, NULL},
    {"end_stone_brick_slab", 0, 0, NULL, NULL},
    {"end_stone_brick_stairs", 0, 0, NULL, NULL},
    {"end_stone_brick_wall", 0, 0, NULL, NULL},
    {"bricks", 0, 0, NULL, NULL},
    {"brick_slab", 0, 0, NULL, NULL},
    {"brick_stairs", 0, 0, NULL, NULL},
    {"brick_wall", 0, 0, NULL, NULL},
    {"sandstone", 0, 0, NULL, NULL},
    {"sandstone_slab", 0, 0, NULL, NULL},
    {"sandstone_stairs", 0, 0, NULL, NULL},
    {"sandstone_wall", 0, 0, NULL, NULL},
    {"chiseled_sandstone", 0, 0, NULL, NULL},
    {"smooth_sandstone", 0, 0, NULL, NULL},
    {"smooth_sandstone_slab", 0, 0, NULL, NULL},
    {"smooth_sandstone_stairs", 0, 0, NULL, NULL},
    {"cut_sandstone", 0, 0, NULL, NULL},
    {"cut_sandstone_slab", 0, 0, NULL, NULL},
    {"red_sandstone", 0, 0, NULL, NULL},
    {"red_sandstone_slab", 0, 0, NULL, NULL},
    {"red_sandstone_stairs", 0, 0, NULL, NULL},
    {"red_sandstone_wall", 0, 0, NULL, NULL},
    {"chiseled_red_sandstone", 0, 0, NULL, NULL},
    {"smooth_red_sandstone", 0, 0, NULL, NULL},
    {"smooth_red_sandstone_slab", 0, 0, NULL, NULL},
    {"smooth_red_sandstone_stairs", 0, 0, NULL, NULL},
    {"cut_red_sandstone", 0, 0, NULL, NULL},
    {"cut_red_sandstone_slab", 0, 0, NULL, NULL},
    {"quartz_block", 0, 0, NULL, NULL},
    {"quartz_slab", 0, 0, NULL, NULL},
    {"quartz_stairs", 0, 0, NULL, NULL},
    {"quartz_pillar", 0, 0, NULL, NULL},
    {"chiseled_quartz", 0, 0, NULL, NULL},
    {"nether_bricks", 0, 0, NULL, NULL},
    {"nether_brick_slab", 0, 0, NULL, NULL},
    {"nether_brick_stairs", 0, 0, NULL, NULL},
    {"nether_brick_fence", 0, 0, NULL, NULL},
    {"red_nether_bricks", 0, 0, NULL, NULL},
    {"red_nether_brick_slab", 0, 0, NULL, NULL},
    {"red_nether_brick_stairs", 0, 0, NULL, NULL},
    {"red_nether_brick_fence", 0, 0, NULL, NULL},
    {"prismarine", 0, 0, NULL, NULL},
    {"prismarine_bricks", 0, 0, NULL, NULL},
    {"dark_prismarine", 0, 0, NULL, NULL},
    {"dirt", 0, 0, NULL, NULL},
    {"grass_block", 0, 0, NULL, NULL},
    {"grass_path", 0, 0, NULL, NULL},
    {"farmland", 0, 0, NULL, NULL},
    {"podzol", 0, 0, NULL, NULL},
    {"mycelium", 0, 0, NULL, NULL},
    {"coarse_dirt", 0, 0, NULL, NULL},
    {"gravel", 0, 0, NULL, NULL},
    {"sand", 0, 0, NULL, NULL},
    {"red_sand", 0, 0, NULL, NULL},
    {"glass", 0, 0, NULL, NULL},
    {"glass_pane", 0, 0, NULL, NULL},
    {"snow_layer", 0, 0, NULL, NULL},
    {"snow_block", 0, 0, NULL, NULL},
    {"clay", 0, 0, NULL, NULL},
    {"terracotta", 0, 0, NULL, NULL},
    {"obsidian", 0, 0, NULL, NULL},
    {"bedrock", 0, 0, NULL, NULL},
    {"netherrack", 0, 0, NULL, NULL},
    {"soul_sand", 0, 0, NULL, NULL},
    {"magma_block", 0, 0, NULL, NULL},
    {"glowstone", 0, 0, NULL, NULL},
    {"aluminum_ore", 0, 0, NULL, NULL},
    {"coal_ore", 0, 0, NULL, NULL},
    {"copper_ore", 0, 0, NULL, NULL},
    {"diamond_ore", 0, 0, NULL, NULL},
    {"emerald_ore", 0, 0, NULL, NULL},
    {"gold_ore", 0, 0, NULL, NULL},
    {"iron_ore", 0, 0, NULL, NULL},
    {"lapis_lazuli_ore", 0, 0, NULL, NULL},
    {"lead_ore", 0, 0, NULL, NULL},
    {"mithril_ore", 0, 0, NULL, NULL},
    {"nether_quartz_ore", 0, 0, NULL, NULL},
    {"nickel_ore", 0, 0, NULL, NULL},
    {"redstone_ore", 0, 0, NULL, NULL},
    {"ruby_ore", 0, 0, NULL, NULL},
    {"saphire_ore", 0, 0, NULL, NULL},
    {"silver_ore", 0, 0, NULL, NULL},
    {"tin_ore", 0, 0, NULL, NULL},
    {"titanium_ore", 0, 0, NULL, NULL},
    {"aluminum_block", 0, 0, NULL, NULL},
    {"bronze_block", 0, 0, NULL, NULL},
    {"charcoal_block", 0, 0, NULL, NULL},
    {"coal_block", 0, 0, NULL, NULL},
    {"copper_block", 0, 0, NULL, NULL},
    {"diamond_block", 0, 0, NULL, NULL},
    {"emerald_block", 0, 0, NULL, NULL},
    {"gold_block", 0, 0, NULL, NULL},
    {"iron_block", 0, 0, NULL, NULL},
    {"lapis_lazuli_block", 0, 0, NULL, NULL},
    {"lead_block", 0, 0, NULL, NULL},
    {"mithril_block", 0, 0, NULL, NULL},
    {"nether_quartz_block", 0, 0, NULL, NULL},
    {"nickel_block", 0, 0, NULL, NULL},
    {"redstone_block", 0, 0, NULL, NULL},
    {"ruby_block", 0, 0, NULL, NULL},
    {"saphire_block", 0, 0, NULL, NULL},
    {"silver_block", 0, 0, NULL, NULL},
    {"steel_block", 0, 0, NULL, NULL},
    {"tin_block", 0, 0, NULL, NULL},
    {"titanium_block", 0, 0, NULL, NULL},
    {"anvil", 0, 0, NULL, NULL},
    {"barrel", 0, 0, NULL, NULL},
    {"barrier", 0, 0, NULL, NULL},
    {"bell", 0, 0, NULL, NULL},
    {"blast_furnace", 0, 0, NULL, NULL},
    {"bookshelf", 0, 0, NULL, NULL},
    {"brewing_stand", 0, 0, NULL, NULL},
    {"cake", 0, 0, NULL, NULL},
    {"cartography_table", 0, 0, NULL, NULL},
    {"cauldron", 0, 0, NULL, NULL},
    {"chain_command_block", 0, 0, NULL, NULL},
    {"chest", 0, 0, NULL, NULL},
    {"chipped_anvil", 0, 0, NULL, NULL},
    {"command_block", 0, 0, NULL, NULL},
    {"composter", 0, 0, NULL, NULL},
    {"crafting_table", 0, 0, NULL, NULL},
    {"damaged_anvil", 0, 0, NULL, NULL},
    {"daylight_sensor", 0, 0, NULL, NULL},
    {"dispenser", 0, 0, NULL, NULL},
    {"double_chest", 0, 0, NULL, NULL},
    {"dropper", 0, 0, NULL, NULL},
    {"ender_chest", 0, 0, NULL, NULL},
    {"enchantment_table", 0, 0, NULL, NULL},
    {"fletching_table", 0, 0, NULL, NULL},
    {"flower_pot", 0, 0, NULL, NULL},
    {"furnace", 0, 0, NULL, NULL},
    {"hopper", 0, 0, NULL, NULL},
    {"jukebox", 0, 0, NULL, NULL},
    {"lecturn", 0, 0, NULL, NULL},
    {"note_block", 0, 0, NULL, NULL},
    {"observer", 0, 0, NULL, NULL},
    {"piston", 0, 0, NULL, NULL},
    {"piston_head", 0, 0, NULL, NULL},
    {"redstone_lamp", 0, 0, NULL, NULL},
    {"smithing_table", 0, 0, NULL, NULL},
    {"sticky_piston", 0, 0, NULL, NULL},
    {"sticky_piston_head", 0, 0, NULL, NULL},
    {"trapped_chest", 0, 0, NULL, NULL},
    {"tnt", 0, 0, NULL, NULL},
    {"torch", 0, 0, NULL, NULL},
    {"redstone_torch", 0, 0, NULL, NULL},
    {"wall_torch", 0, 0, NULL, NULL},
    {"redstone_wall_torch", 0, 0, NULL, NULL},
    {"redstone_comparator", 0, 0, NULL, NULL},
    {"redstone_repeater", 0, 0, NULL, NULL},
    {"iron_pressure_plate", 0, 0, NULL, NULL},
    {"stone_pressure_plate", 0, 0, NULL, NULL},
    {"gold_pressure_plate", 0, 0, NULL, NULL},
    {"rail", 0, 0, NULL, NULL},
    {"powered_rail", 0, 0, NULL, NULL},
    {"activator_rail", 0, 0, NULL, NULL},
    {"detector_rail", 0, 0, NULL, NULL},
    {"lever", 0, 0, NULL, NULL},
    {"wood_button", 0, 0, NULL, NULL},
    {"stone_button", 0, 0, NULL, NULL},
    {"fire", 0, 0, NULL, NULL},
    {"tripwire", 0, 0, NULL, NULL},
    {"tripwire_hook", 0, 0, NULL, NULL},
    {"iron_trapdoor", 0, 0, NULL, NULL},
    {"iron_door", 0, 0, NULL, NULL},
    {"end_rood", 0, 0, NULL, NULL},
    {"draggon_egg", 0, 0, NULL, NULL},
    {"end_portal_frame", 0, 0, NULL, NULL},
    {"sea_lantern", 0, 0, NULL, NULL},
    {"sponge", 0, 0, NULL, NULL},
    {"wet_sponge", 0, 0, NULL, NULL},
    {"slime_block", 0, 0, NULL, NULL},
    {"water", 0, 0, NULL, NULL},
    {"lava", 0, 0, NULL, NULL},
    {"cobweb", 0, 0, NULL, NULL},
    {"ladder", 0, 0, NULL, NULL},
    {"iron_bars", 0, 0, NULL, NULL},
    {"monster_spawner", 0, 0, NULL, NULL},
    {"jack_o_lantern", 0, 0, NULL, NULL},
    {"ice", 0, 0, NULL, NULL},
    {"packed_ice", 0, 0, NULL, NULL},
    {"oak_sapling", 0, 0, NULL, NULL},
    {"oak_leaves", 0, 0, NULL, NULL},
    {"oak_log", 0, 0, NULL, NULL},
    {"oak_stripped_log", 0, 0, NULL, NULL},
    {"oak_plank", 0, 0, NULL, NULL},
    {"oak_slab", 0, 0, NULL, NULL},
    {"oak_stairs", 0, 0, NULL, NULL},
    {"oak_fence", 0, 0, NULL, NULL},
    {"oak_fence_gate", 0, 0, NULL, NULL},
    {"oak_boat", 0, 0, NULL, NULL},
    {"oak_door", 0, 0, NULL, NULL},
    {"oak_trapdoor", 0, 0, NULL, NULL},
    {"oak_presure_plate", 0, 0, NULL, NULL},
    {"oak_button", 0, 0, NULL, NULL},
    {"oak_sign", 0, 0, NULL, NULL},
    {"birch_sapling", 0, 0, NULL, NULL},
    {"birch_leaves", 0, 0, NULL, NULL},
    {"birch_log", 0, 0, NULL, NULL},
    {"birch_stripped_log", 0, 0, NULL, NULL},
    {"birch_plank", 0, 0, NULL, NULL},
    {"birch_stairs", 0, 0, NULL, NULL},
    {"birch_fence", 0, 0, NULL, NULL},
    {"birch_fence_gate", 0, 0, NULL, NULL},
    {"birch_boat", 0, 0, NULL, NULL},
    {"birch_door", 0, 0, NULL, NULL},
    {"birch_trapdoor", 0, 0, NULL, NULL},
    {"birch_presure_plate", 0, 0, NULL, NULL},
    {"birch_button", 0, 0, NULL, NULL},
    {"birch_sign", 0, 0, NULL, NULL},
    {"spruce_sapling", 0, 0, NULL, NULL},
    {"spruce_leaves", 0, 0, NULL, NULL},
    {"spruce_log", 0, 0, NULL, NULL},
    {"spruce_stripped_log", 0, 0, NULL, NULL},
    {"spruce_plank", 0, 0, NULL, NULL},
    {"spruce_slab", 0, 0, NULL, NULL},
    {"spruce_stairs", 0, 0, NULL, NULL},
    {"spruce_fence", 0, 0, NULL, NULL},
    {"spruce_fence_gate", 0, 0, NULL, NULL},
    {"spruce_boat", 0, 0, NULL, NULL},
    {"spruce_door", 0, 0, NULL, NULL},
    {"spruce_trapdoor", 0, 0, NULL, NULL},
    {"spruce_presure_plate", 0, 0, NULL, NULL},
    {"spruce_button", 0, 0, NULL, NULL},
    {"spruce_sign", 0, 0, NULL, NULL},
    {"jungle_sapling", 0, 0, NULL, NULL},
    {"jungle_leaves", 0, 0, NULL, NULL},
    {"jungle_log", 0, 0, NULL, NULL},
    {"jungle_stripped_log", 0, 0, NULL, NULL},
    {"jungle_plank", 0, 0, NULL, NULL},
    {"jungle_slab", 0, 0, NULL, NULL},
    {"jungle_stairs", 0, 0, NULL, NULL},
    {"jungle_fence", 0, 0, NULL, NULL},
    {"jungle_fence_gate", 0, 0, NULL, NULL},
    {"jungle_boat", 0, 0, NULL, NULL},
    {"jungle_door", 0, 0, NULL, NULL},
    {"jungle_trapdoor", 0, 0, NULL, NULL},
    {"jungle_presure_plate", 0, 0, NULL, NULL},
    {"jungle_button", 0, 0, NULL, NULL},
    {"jungle_sign", 0, 0, NULL, NULL},
    {"redwood_sapling", 0, 0, NULL, NULL},
    {"redwood_leaves", 0, 0, NULL, NULL},
    {"redwood_log", 0, 0, NULL, NULL},
    {"redwood_stripped_log", 0, 0, NULL, NULL},
    {"redwood_plank", 0, 0, NULL, NULL},
    {"redwood_slab", 0, 0, NULL, NULL},
    {"redwood_stairs", 0, 0, NULL, NULL},
    {"redwood_fence", 0, 0, NULL, NULL},
    {"redwood_fence_gate", 0, 0, NULL, NULL},
    {"redwood_boat", 0, 0, NULL, NULL},
    {"redwood_door", 0, 0, NULL, NULL},
    {"redwood_trapdoor", 0, 0, NULL, NULL},
    {"redwood_presure_plate", 0, 0, NULL, NULL},
    {"redwood_button", 0, 0, NULL, NULL},
    {"redwood_sign", 0, 0, NULL, NULL},
    {"acacia_sapling", 0, 0, NULL, NULL},
    {"acacia_leaves", 0, 0, NULL, NULL},
    {"acacia_log", 0, 0, NULL, NULL},
    {"acacia_stripped_log", 0, 0, NULL, NULL},
    {"acacia_plank", 0, 0, NULL, NULL},
    {"acacia_slab", 0, 0, NULL, NULL},
    {"acacia_stairs", 0, 0, NULL, NULL},
    {"acacia_fence", 0, 0, NULL, NULL},
    {"acacia_fence_gate", 0, 0, NULL, NULL},
    {"acacia_boat", 0, 0, NULL, NULL},
    {"acacia_door", 0, 0, NULL, NULL},
    {"acacia_trapdoor", 0, 0, NULL, NULL},
    {"acacia_presure_plate", 0, 0, NULL, NULL},
    {"acacia_button", 0, 0, NULL, NULL},
    {"acacia_sign", 0, 0, NULL, NULL},
    {"dark_oak_sapling", 0, 0, NULL, NULL},
    {"dark_oak_leaves", 0, 0, NULL, NULL},
    {"dark_oak_log", 0, 0, NULL, NULL},
    {"dark_oak_stripped_log", 0, 0, NULL, NULL},
    {"dark_oak_plank", 0, 0, NULL, NULL},
    {"dark_oak_slab", 0, 0, NULL, NULL},
    {"dark_oak_stairs", 0, 0, NULL, NULL},
    {"dark_oak_fence", 0, 0, NULL, NULL},
    {"dark_oak_fence_gate", 0, 0, NULL, NULL},
    {"dark_oak_boat", 0, 0, NULL, NULL},
    {"dark_oak_door", 0, 0, NULL, NULL},
    {"dark_oak_trapdoor", 0, 0, NULL, NULL},
    {"dark_oak_presure_plate", 0, 0, NULL, NULL},
    {"dark_oak_button", 0, 0, NULL, NULL},
    {"dark_oak_sign", 0, 0, NULL, NULL},
    {"black_banner", 0, 0, NULL, NULL},
    {"gray_banner", 0, 0, NULL, NULL},
    {"light_gray_banner", 0, 0, NULL, NULL},
    {"white_banner", 0, 0, NULL, NULL},
    {"pink_banner", 0, 0, NULL, NULL},
    {"red_banner", 0, 0, NULL, NULL},
    {"orange_banner", 0, 0, NULL, NULL},
    {"yellow_banner", 0, 0, NULL, NULL},
    {"lime_banner", 0, 0, NULL, NULL},
    {"green_banner", 0, 0, NULL, NULL},
    {"cyan_banner", 0, 0, NULL, NULL},
    {"light_blue_banner", 0, 0, NULL, NULL},
    {"blue_banner", 0, 0, NULL, NULL},
    {"purple_banner", 0, 0, NULL, NULL},
    {"magenta_banner", 0, 0, NULL, NULL},
    {"brown_banner", 0, 0, NULL, NULL},
    {"black_bed", 0, 0, NULL, NULL},
    {"gray_bed", 0, 0, NULL, NULL},
    {"light_gray_bed", 0, 0, NULL, NULL},
    {"white_bed", 0, 0, NULL, NULL},
    {"pink_bed", 0, 0, NULL, NULL},
    {"red_bed", 0, 0, NULL, NULL},
    {"orange_bed", 0, 0, NULL, NULL},
    {"yellow_bed", 0, 0, NULL, NULL},
    {"lime_bed", 0, 0, NULL, NULL},
    {"green_bed", 0, 0, NULL, NULL},
    {"cyan_bed", 0, 0, NULL, NULL},
    {"light_blue_bed", 0, 0, NULL, NULL},
    {"blue_bed", 0, 0, NULL, NULL},
    {"purple_bed", 0, 0, NULL, NULL},
    {"magenta_bed", 0, 0, NULL, NULL},
    {"brown_bed", 0, 0, NULL, NULL},
    {"black_wool", 0, 0, NULL, NULL},
    {"gray_wool", 0, 0, NULL, NULL},
    {"light_gray_wool", 0, 0, NULL, NULL},
    {"white_wool", 0, 0, NULL, NULL},
    {"pink_wool", 0, 0, NULL, NULL},
    {"red_wool", 0, 0, NULL, NULL},
    {"orange_wool", 0, 0, NULL, NULL},
    {"yellow_wool", 0, 0, NULL, NULL},
    {"lime_wool", 0, 0, NULL, NULL},
    {"green_wool", 0, 0, NULL, NULL},
    {"cyan_wool", 0, 0, NULL, NULL},
    {"light_blue_wool", 0, 0, NULL, NULL},
    {"blue_wool", 0, 0, NULL, NULL},
    {"purple_wool", 0, 0, NULL, NULL},
    {"magenta_wool", 0, 0, NULL, NULL},
    {"brown_wool", 0, 0, NULL, NULL},
    {"black_carpet", 0, 0, NULL, NULL},
    {"gray_carpet", 0, 0, NULL, NULL},
    {"light_gray_carpet", 0, 0, NULL, NULL},
    {"white_carpet", 0, 0, NULL, NULL},
    {"pink_carpet", 0, 0, NULL, NULL},
    {"red_carpet", 0, 0, NULL, NULL},
    {"orange_carpet", 0, 0, NULL, NULL},
    {"yellow_carpet", 0, 0, NULL, NULL},
    {"lime_carpet", 0, 0, NULL, NULL},
    {"green_carpet", 0, 0, NULL, NULL},
    {"cyan_carpet", 0, 0, NULL, NULL},
    {"light_blue_carpet", 0, 0, NULL, NULL},
    {"blue_carpet", 0, 0, NULL, NULL},
    {"purple_carpet", 0, 0, NULL, NULL},
    {"magenta_carpet", 0, 0, NULL, NULL},
    {"brown_carpet", 0, 0, NULL, NULL},
    {"black_stained_glass", 0, 0, NULL, NULL},
    {"gray_stained_glass", 0, 0, NULL, NULL},
    {"light_gray_stained_glass", 0, 0, NULL, NULL},
    {"white_stained_glass", 0, 0, NULL, NULL},
    {"pink_stained_glass", 0, 0, NULL, NULL},
    {"red_stained_glass", 0, 0, NULL, NULL},
    {"orange_stained_glass", 0, 0, NULL, NULL},
    {"yellow_stained_glass", 0, 0, NULL, NULL},
    {"lime_stained_glass", 0, 0, NULL, NULL},
    {"green_stained_glass", 0, 0, NULL, NULL},
    {"cyan_stained_glass", 0, 0, NULL, NULL},
    {"light_blue_stained_glass", 0, 0, NULL, NULL},
    {"blue_stained_glass", 0, 0, NULL, NULL},
    {"purple_stained_glass", 0, 0, NULL, NULL},
    {"magenta_stained_glass", 0, 0, NULL, NULL},
    {"brown_stained_glass", 0, 0, NULL, NULL},
    {"black_stained_glass_pane", 0, 0, NULL, NULL},
    {"gray_stained_glass_pane", 0, 0, NULL, NULL},
    {"light_gray_stained_glass_pane", 0, 0, NULL, NULL},
    {"white_stained_glass_pane", 0, 0, NULL, NULL},
    {"pink_stained_glass_pane", 0, 0, NULL, NULL},
    {"red_stained_glass_pane", 0, 0, NULL, NULL},
    {"orange_stained_glass_pane", 0, 0, NULL, NULL},
    {"yellow_stained_glass_pane", 0, 0, NULL, NULL},
    {"lime_stained_glass_pane", 0, 0, NULL, NULL},
    {"green_stained_glass_pane", 0, 0, NULL, NULL},
    {"cyan_stained_glass_pane", 0, 0, NULL, NULL},
    {"light_blue_stained_glass_pane", 0, 0, NULL, NULL},
    {"blue_stained_glass_pane", 0, 0, NULL, NULL},
    {"purple_stained_glass_pane", 0, 0, NULL, NULL},
    {"magenta_stained_glass_pane", 0, 0, NULL, NULL},
    {"brown_stained_glass_pane", 0, 0, NULL, NULL},
    {"black_terracotta", 0, 0, NULL, NULL},
    {"gray_terracotta", 0, 0, NULL, NULL},
    {"light_gray_terracotta", 0, 0, NULL, NULL},
    {"white_terracotta", 0, 0, NULL, NULL},
    {"pink_terracotta", 0, 0, NULL, NULL},
    {"red_terracotta", 0, 0, NULL, NULL},
    {"orange_terracotta", 0, 0, NULL, NULL},
    {"yellow_terracotta", 0, 0, NULL, NULL},
    {"lime_terracotta", 0, 0, NULL, NULL},
    {"green_terracotta", 0, 0, NULL, NULL},
    {"cyan_terracotta", 0, 0, NULL, NULL},
    {"light_blue_terracotta", 0, 0, NULL, NULL},
    {"blue_terracotta", 0, 0, NULL, NULL},
    {"purple_terracotta", 0, 0, NULL, NULL},
    {"magenta_terracotta", 0, 0, NULL, NULL},
    {"brown_terracotta", 0, 0, NULL, NULL},
    {"black_glazed_terracotta", 0, 0, NULL, NULL},
    {"gray_glazed_terracotta", 0, 0, NULL, NULL},
    {"light_gray_glazed_terracotta", 0, 0, NULL, NULL},
    {"white_glazed_terracotta", 0, 0, NULL, NULL},
    {"pink_glazed_terracotta", 0, 0, NULL, NULL},
    {"red_glazed_terracotta", 0, 0, NULL, NULL},
    {"orange_glazed_terracotta", 0, 0, NULL, NULL},
    {"yellow_glazed_terracotta", 0, 0, NULL, NULL},
    {"lime_glazed_terracotta", 0, 0, NULL, NULL},
    {"green_glazed_terracotta", 0, 0, NULL, NULL},
    {"cyan_glazed_terracotta", 0, 0, NULL, NULL},
    {"light_blue_glazed_terracotta", 0, 0, NULL, NULL},
    {"blue_glazed_terracotta", 0, 0, NULL, NULL},
    {"purple_glazed_terracotta", 0, 0, NULL, NULL},
    {"magenta_glazed_terracotta", 0, 0, NULL, NULL},
    {"brown_glazed_terracotta", 0, 0, NULL, NULL},
    {"black_concrete", 0, 0, NULL, NULL},
    {"gray_concrete", 0, 0, NULL, NULL},
    {"light_gray_concrete", 0, 0, NULL, NULL},
    {"white_concrete", 0, 0, NULL, NULL},
    {"pink_concrete", 0, 0, NULL, NULL},
    {"red_concrete", 0, 0, NULL, NULL},
    {"orange_concrete", 0, 0, NULL, NULL},
    {"yellow_concrete", 0, 0, NULL, NULL},
    {"lime_concrete", 0, 0, NULL, NULL},
    {"green_concrete", 0, 0, NULL, NULL},
    {"cyan_concrete", 0, 0, NULL, NULL},
    {"light_blue_concrete", 0, 0, NULL, NULL},
    {"blue_concrete", 0, 0, NULL, NULL},
    {"purple_concrete", 0, 0, NULL, NULL},
    {"magenta_concrete", 0, 0, NULL, NULL},
    {"brown_concrete", 0, 0, NULL, NULL},
    {"black_concrete_powder", 0, 0, NULL, NULL},
    {"gray_concrete_powder", 0, 0, NULL, NULL},
    {"light_gray_concrete_powder", 0, 0, NULL, NULL},
    {"white_concrete_powder", 0, 0, NULL, NULL},
    {"pink_concrete_powder", 0, 0, NULL, NULL},
    {"red_concrete_powder", 0, 0, NULL, NULL},
    {"orange_concrete_powder", 0, 0, NULL, NULL},
    {"yellow_concrete_powder", 0, 0, NULL, NULL},
    {"lime_concrete_powder", 0, 0, NULL, NULL},
    {"green_concrete_powder", 0, 0, NULL, NULL},
    {"cyan_concrete_powder", 0, 0, NULL, NULL},
    {"light_blue_concrete_powder", 0, 0, NULL, NULL},
    {"blue_concrete_powder", 0, 0, NULL, NULL},
    {"purple_concrete_powder", 0, 0, NULL, NULL},
    {"magenta_concrete_powder", 0, 0, NULL, NULL},
    {"brown_concrete_powder", 0, 0, NULL, NULL},
    {"black_shulker_box", 0, 0, NULL, NULL},
    {"gray_shulker_box", 0, 0, NULL, NULL},
    {"light_gray_shulker_box", 0, 0, NULL, NULL},
    {"white_shulker_box", 0, 0, NULL, NULL},
    {"pink_shulker_box", 0, 0, NULL, NULL},
    {"red_shulker_box", 0, 0, NULL, NULL},
    {"orange_shulker_box", 0, 0, NULL, NULL},
    {"yellow_shulker_box", 0, 0, NULL, NULL},
    {"lime_shulker_box", 0, 0, NULL, NULL},
    {"green_shulker_box", 0, 0, NULL, NULL},
    {"cyan_shulker_box", 0, 0, NULL, NULL},
    {"light_blue_shulker_box", 0, 0, NULL, NULL},
    {"blue_shulker_box", 0, 0, NULL, NULL},
    {"purple_shulker_box", 0, 0, NULL, NULL},
    {"magenta_shulker_box", 0, 0, NULL, NULL},
    {"brown_shulker_box", 0, 0, NULL, NULL},
    {"crushed_iron_ore", 0, 0, NULL, NULL},
    {"iron_ingot", 0, 0, NULL, NULL},
    {"iron_nugget", 0, 0, NULL, NULL},
    {"crushed_gold_ore", 0, 0, NULL, NULL},
    {"gold_ingot", 0, 0, NULL, NULL},
    {"gold_nugget", 0, 0, NULL, NULL},
    {"crushed_tin_ore", 0, 0, NULL, NULL},
    {"tin_ingot", 0, 0, NULL, NULL},
    {"tin_nugget", 0, 0, NULL, NULL},
    {"crushed_copper_ore", 0, 0, NULL, NULL},
    {"copper_ingot", 0, 0, NULL, NULL},
    {"copper_nugget", 0, 0, NULL, NULL},
    {"crushed_lead_ore", 0, 0, NULL, NULL},
    {"lead_ingot", 0, 0, NULL, NULL},
    {"lead_nugget", 0, 0, NULL, NULL},
    {"crushed_aluminum_ore", 0, 0, NULL, NULL},
    {"aluminum_ingot", 0, 0, NULL, NULL},
    {"aluminum_nugget", 0, 0, NULL, NULL},
    {"crushed_nickel_ore", 0, 0, NULL, NULL},
    {"nickel_ingot", 0, 0, NULL, NULL},
    {"nickel_nugget", 0, 0, NULL, NULL},
    {"crushed_silver_ore", 0, 0, NULL, NULL},
    {"silver_ingot", 0, 0, NULL, NULL},
    {"silver_nugget", 0, 0, NULL, NULL},
    {"crushed_titanium_ore", 0, 0, NULL, NULL},
    {"titanium_ingot", 0, 0, NULL, NULL},
    {"titanium_nugget", 0, 0, NULL, NULL},
    {"crushed_mithril_ore", 0, 0, NULL, NULL},
    {"mithril_ingot", 0, 0, NULL, NULL},
    {"mithril_nugget", 0, 0, NULL, NULL},
    {"bronze_ingot", 0, 0, NULL, NULL},
    {"bronze_nugget", 0, 0, NULL, NULL},
    {"steel_ingot", 0, 0, NULL, NULL},
    {"steel_nugget", 0, 0, NULL, NULL},
    {"coal", 0, 0, NULL, NULL},
    {"redstone_dust", 0, 0, NULL, NULL},
    {"lapis_lazuli", 0, 0, NULL, NULL},
    {"emerald", 0, 0, NULL, NULL},
    {"diamond", 0, 0, NULL, NULL},
    {"ruby", 0, 0, NULL, NULL},
    {"saphire", 0, 0, NULL, NULL},
    {"nether_quartz", 0, 0, NULL, NULL},
    {"nether_brick", 0, 0, NULL, NULL},
    {"red_nether_brick", 0, 0, NULL, NULL},
    {"glowstone_dust", 0, 0, NULL, NULL},
    {"charcoal", 0, 0, NULL, NULL},
    {"brick", 0, 0, NULL, NULL},
    {"clay_ball", 0, 0, NULL, NULL},
    {"wooden_sword", 0, 0, NULL, NULL},
    {"wooden_axe", 0, 0, NULL, NULL},
    {"wooden_shovel", 0, 0, NULL, NULL},
    {"wooden_pickaxe", 0, 0, NULL, NULL},
    {"wooden_hoe", 0, 0, NULL, NULL},
    {"stone_sword", 0, 0, NULL, NULL},
    {"stone_axe", 0, 0, NULL, NULL},
    {"stone_shovel", 0, 0, NULL, NULL},
    {"stone_pickaxe", 0, 0, NULL, NULL},
    {"stone_hoe", 0, 0, NULL, NULL},
    {"iron_sword", 0, 0, NULL, NULL},
    {"iron_axe", 0, 0, NULL, NULL},
    {"iron_shovel", 0, 0, NULL, NULL},
    {"iron_pickaxe", 0, 0, NULL, NULL},
    {"iron_hoe", 0, 0, NULL, NULL},
    {"steel_sword", 0, 0, NULL, NULL},
    {"steel_axe", 0, 0, NULL, NULL},
    {"steel_shovel", 0, 0, NULL, NULL},
    {"steel_pickaxe", 0, 0, NULL, NULL},
    {"steel_hoe", 0, 0, NULL, NULL},
    {"diamond_sword", 0, 0, NULL, NULL},
    {"diamond_axe", 0, 0, NULL, NULL},
    {"diamond_shovel", 0, 0, NULL, NULL},
    {"diamond_pickaxe", 0, 0, NULL, NULL},
    {"diamond_hoe", 0, 0, NULL, NULL},
    {"wooden_sheild", 0, 0, NULL, NULL},
    {"iron_sheild", 0, 0, NULL, NULL},
    {"titanium_sheild", 0, 0, NULL, NULL},
    {"bucket", 0, 0, NULL, NULL},
    {"rope", 0, 0, NULL, NULL},
    {"bow", 0, 0, NULL, NULL},
    {"fishing_rod", 0, 0, NULL, NULL},
    {"shears", 0, 0, NULL, NULL},
    {"fint_and_steel", 0, 0, NULL, NULL},
    {"bonemeal", 0, 0, NULL, NULL},
    {"leather_cap", 0, 0, NULL, NULL},
    {"leather_vest", 0, 0, NULL, NULL},
    {"leather_pants", 0, 0, NULL, NULL},
    {"leather_stockings", 0, 0, NULL, NULL},
    {"chainmail_cap", 0, 0, NULL, NULL},
    {"chainmail_vest", 0, 0, NULL, NULL},
    {"chainmail_pants", 0, 0, NULL, NULL},
    {"chainmail_stockings", 0, 0, NULL, NULL},
    {"mithril_cap", 0, 0, NULL, NULL},
    {"mithril_vest", 0, 0, NULL, NULL},
    {"mithril_pants", 0, 0, NULL, NULL},
    {"mithril_stockings", 0, 0, NULL, NULL},
    {"iron_helmet", 0, 0, NULL, NULL},
    {"iron_chestplate", 0, 0, NULL, NULL},
    {"iron_leggings", 0, 0, NULL, NULL},
    {"iron_boots", 0, 0, NULL, NULL},
    {"steel_helmet", 0, 0, NULL, NULL},
    {"steel_chestplate", 0, 0, NULL, NULL},
    {"steel_leggings", 0, 0, NULL, NULL},
    {"steel_boots", 0, 0, NULL, NULL},
    {"diamond_helmet", 0, 0, NULL, NULL},
    {"diamond_chestplate", 0, 0, NULL, NULL},
    {"diamond_leggings", 0, 0, NULL, NULL},
    {"diamond_boots", 0, 0, NULL, NULL},
    {"titanium_helmet", 0, 0, NULL, NULL},
    {"titanium_chestplate", 0, 0, NULL, NULL},
    {"titanium_leggings", 0, 0, NULL, NULL},
    {"titanium_boots", 0, 0, NULL, NULL},
    {"raw_beef", 0, 0, NULL, NULL},
    {"steak", 0, 0, NULL, NULL},
    {"raw_mutton", 0, 0, NULL, NULL},
    {"cooked_mutton", 0, 0, NULL, NULL},
    {"raw_chicken", 0, 0, NULL, NULL},
    {"cooked_chicken", 0, 0, NULL, NULL},
    {"raw_porkchop", 0, 0, NULL, NULL},
    {"cooked_porkchop", 0, 0, NULL, NULL},
    {"raw_rabbit", 0, 0, NULL, NULL},
    {"cooked_rabbit", 0, 0, NULL, NULL},
    {"raw_salmon", 0, 0, NULL, NULL},
    {"cooked_salmon", 0, 0, NULL, NULL},
    {"raw_cod", 0, 0, NULL, NULL},
    {"cooked_cod", 0, 0, NULL, NULL},
    {"raw_tuna", 0, 0, NULL, NULL},
    {"cooked_tuna", 0, 0, NULL, NULL},
    {"raw_bass", 0, 0, NULL, NULL},
    {"cooked_bass", 0, 0, NULL, NULL},
    {"apple", 0, 0, NULL, NULL},
    {"beetroot_seeds", 0, 0, NULL, NULL},
    {"beetroot_plant", 0, 0, NULL, NULL},
    {"beetroot", 0, 0, NULL, NULL},
    {"berry_bush", 0, 0, NULL, NULL},
    {"berries", 0, 0, NULL, NULL},
    {"brown_mushroom", 0, 0, NULL, NULL},
    {"carrot_plant", 0, 0, NULL, NULL},
    {"carrot", 0, 0, NULL, NULL},
    {"mellon_stem", 0, 0, NULL, NULL},
    {"mellon", 0, 0, NULL, NULL},
    {"mellon_wedge", 0, 0, NULL, NULL},
    {"potato_plant", 0, 0, NULL, NULL},
    {"potato", 0, 0, NULL, NULL},
    {"pumpkin_stem", 0, 0, NULL, NULL},
    {"pumpkin", 0, 0, NULL, NULL},
    {"red_mushroom", 0, 0, NULL, NULL},
    {"sugar_canes", 0, 0, NULL, NULL},
    {"sugar", 0, 0, NULL, NULL},
    {"wheat_seeds", 0, 0, NULL, NULL},
    {"wheat_plant", 0, 0, NULL, NULL},
    {"wheat", 0, 0, NULL, NULL},
    {"bamboo", 0, 0, NULL, NULL},
    {"cactus", 0, 0, NULL, NULL},
    {"dead_brush", 0, 0, NULL, NULL},
    {"dry_reeds", 0, 0, NULL, NULL},
    {"fern", 0, 0, NULL, NULL},
    {"grass", 0, 0, NULL, NULL},
    {"kelp", 0, 0, NULL, NULL},
    {"lily_pad", 0, 0, NULL, NULL},
    {"seagrass", 0, 0, NULL, NULL},
    {"sweet_berry_bush", 0, 0, NULL, NULL},
    {"tall_fern", 0, 0, NULL, NULL},
    {"tall_grass", 0, 0, NULL, NULL},
    {"tall_seagrass", 0, 0, NULL, NULL},
    {"vines", 0, 0, NULL, NULL},
    {"allium", 0, 0, NULL, NULL},
    {"azure_bluet", 0, 0, NULL, NULL},
    {"blue_orchid", 0, 0, NULL, NULL},
    {"dandelion", 0, 0, NULL, NULL},
    {"lilac", 0, 0, NULL, NULL},
    {"orange_tulip", 0, 0, NULL, NULL},
    {"oxeye_daisy", 0, 0, NULL, NULL},
    {"peony", 0, 0, NULL, NULL},
    {"pink_tulip", 0, 0, NULL, NULL},
    {"poppy", 0, 0, NULL, NULL},
    {"red_tulip", 0, 0, NULL, NULL},
    {"rose_bush", 0, 0, NULL, NULL},
    {"sunflower", 0, 0, NULL, NULL},
    {"white_tulip", 0, 0, NULL, NULL}
};



#define AIR                             (   0)
#define STONE                           (   1)
#define STONE_SLAB                      (   2)
#define STONE_STAIRS                    (   3)
#define SMOOTH_STONE                    (   4)
#define SMOOTH_STONE_SLAB               (   5)
#define SMOOTH_STONE_STAIRS             (   6)
#define STONE_BRICKS                    (   7)
#define STONE_BRICK_SLAB                (   8)
#define STONE_BRICK_STAIRS              (   9)
#define STONE_BRICK_WALL                (  10)
#define CHISELED_STONE_BRICKS           (  11)
#define CRACKED_STONE_BRICKS            (  12)
#define CRACKED_STONE_BRICK_SLAB        (  13)
#define CRACKED_STONE_BRICK_STAIRS      (  14)
#define CRACKED_STONE_BRICK_WALL        (  15)
#define MOSSY_STONE_BRICKS              (  16)
#define MOSSY_STONE_BRICK_SLAB          (  17)
#define MOSSY_STONE_BRICK_STAIRS        (  18)
#define MOSSY_STONE_BRICK_WALL          (  19)
#define COBBLESTONE                     (  20)
#define COBBLESTONE_SLAB                (  21)
#define COBBLESTONE_STAIRS              (  22)
#define COBBLESTONE_WALL                (  23)
#define MOSSY_COBBLESTONE               (  24)
#define MOSSY_COBBLESTONE_SLAB          (  25)
#define MOSSY_COBBLESTONE_STAIRS        (  26)
#define MOSSY_COBBLESTONE_WALL          (  27)
#define ANDESITE                        (  28)
#define ANDESITE_SLAB                   (  29)
#define ANDESITE_STAIRS                 (  30)
#define ANDESITE_WALL                   (  31)
#define POLISHED_ANDESITE               (  32)
#define POLISHED_ANDESITE_SLAB          (  33)
#define POLISHED_ANDESITE_STAIRS        (  34)
#define DIORITE                         (  35)
#define DIORITE_SLAB                    (  36)
#define DIORITE_STAIRS                  (  37)
#define DIORITE_WALL                    (  38)
#define POLISHED_DIORITE                (  39)
#define POLISHED_DIORITE_SLAB           (  40)
#define POLISHED_DIORITE_STAIRS         (  41)
#define GRANITE                         (  42)
#define GRANITE_SLAB                    (  43)
#define GRANITE_STAIRS                  (  44)
#define GRANITE_WALL                    (  45)
#define POLISHED_GRANITE                (  46)
#define POLISHED_GRANITE_SLAB           (  47)
#define POLISHED_GRANITE_STAIRS         (  48)
#define MARBLE                          (  49)
#define MARBLE_SLAB                     (  50)
#define MARBLE_STAIRS                   (  51)
#define MARBLE_WALL                     (  52)
#define MARBLE_PILLAR                   (  53)
#define CHISELED_MARBLE                 (  54)
#define POLISHED_MARBLE                 (  55)
#define POLISHED_MARBLE_SLAB            (  56)
#define POLISHED_MARBLE_STAIRS          (  57)
#define FLAGSTONE                       (  58)
#define FLAGSTONE_SLAB                  (  59)
#define FLAGSTONE_STAIRS                (  60)
#define FLAGSTONE_WALL                  (  61)
#define LIMESTONE                       (  62)
#define CRUSHED_LIMESTONE               (  63)
#define END_STONE                       (  64)
#define END_STONE_BRICKS                (  65)
#define END_STONE_BRICK_SLAB            (  66)
#define END_STONE_BRICK_STAIRS          (  67)
#define END_STONE_BRICK_WALL            (  68)
#define BRICKS                          (  69)
#define BRICK_SLAB                      (  70)
#define BRICK_STAIRS                    (  71)
#define BRICK_WALL                      (  72)
#define SANDSTONE                       (  73)
#define SANDSTONE_SLAB                  (  74)
#define SANDSTONE_STAIRS                (  75)
#define SANDSTONE_WALL                  (  76)
#define CHISELED_SANDSTONE              (  77)
#define SMOOTH_SANDSTONE                (  78)
#define SMOOTH_SANDSTONE_SLAB           (  79)
#define SMOOTH_SANDSTONE_STAIRS         (  80)
#define CUT_SANDSTONE                   (  81)
#define CUT_SANDSTONE_SLAB              (  82)
#define RED_SANDSTONE                   (  83)
#define RED_SANDSTONE_SLAB              (  84)
#define RED_SANDSTONE_STAIRS            (  85)
#define RED_SANDSTONE_WALL              (  86)
#define CHISELED_RED_SANDSTONE          (  87)
#define SMOOTH_RED_SANDSTONE            (  88)
#define SMOOTH_RED_SANDSTONE_SLAB       (  89)
#define SMOOTH_RED_SANDSTONE_STAIRS     (  90)
#define CUT_RED_SANDSTONE               (  91)
#define CUT_RED_SANDSTONE_SLAB          (  92)
#define QUARTZ_BLOCK                    (  93)
#define QUARTZ_SLAB                     (  94)
#define QUARTZ_STAIRS                   (  95)
#define QUARTZ_PILLAR                   (  96)
#define CHISELED_QUARTZ                 (  97)
#define NETHER_BRICKS                   (  98)
#define NETHER_BRICK_SLAB               (  99)
#define NETHER_BRICK_STAIRS             ( 100)
#define NETHER_BRICK_FENCE              ( 101)
#define RED_NETHER_BRICKS               ( 102)
#define RED_NETHER_BRICK_SLAB           ( 103)
#define RED_NETHER_BRICK_STAIRS         ( 104)
#define RED_NETHER_BRICK_FENCE          ( 105)
#define PRISMARINE                      ( 106)
#define PRISMARINE_BRICKS               ( 107)
#define DARK_PRISMARINE                 ( 108)
#define DIRT                            ( 109)
#define GRASS_BLOCK                     ( 110)
#define GRASS_PATH                      ( 111)
#define FARMLAND                        ( 112)
#define PODZOL                          ( 113)
#define MYCELIUM                        ( 114)
#define COARSE_DIRT                     ( 115)
#define GRAVEL                          ( 116)
#define SAND                            ( 117)
#define RED_SAND                        ( 118)
#define GLASS                           ( 119)
#define GLASS_PANE                      ( 120)
#define SNOW_LAYER                      ( 121)
#define SNOW_BLOCK                      ( 122)
#define CLAY                            ( 123)
#define TERRACOTTA                      ( 124)
#define OBSIDIAN                        ( 125)
#define BEDROCK                         ( 126)
#define NETHERRACK                      ( 127)
#define SOUL_SAND                       ( 128)
#define MAGMA_BLOCK                     ( 129)
#define GLOWSTONE                       ( 130)
#define ALUMINUM_ORE                    ( 131)
#define COAL_ORE                        ( 132)
#define COPPER_ORE                      ( 133)
#define DIAMOND_ORE                     ( 134)
#define EMERALD_ORE                     ( 135)
#define GOLD_ORE                        ( 136)
#define IRON_ORE                        ( 137)
#define LAPIS_LAZULI_ORE                ( 138)
#define LEAD_ORE                        ( 139)
#define MITHRIL_ORE                     ( 140)
#define NETHER_QUARTZ_ORE               ( 141)
#define NICKEL_ORE                      ( 142)
#define REDSTONE_ORE                    ( 143)
#define RUBY_ORE                        ( 144)
#define SAPHIRE_ORE                     ( 145)
#define SILVER_ORE                      ( 146)
#define TIN_ORE                         ( 147)
#define TITANIUM_ORE                    ( 148)
#define ALUMINUM_BLOCK                  ( 149)
#define BRONZE_BLOCK                    ( 150)
#define CHARCOAL_BLOCK                  ( 151)
#define COAL_BLOCK                      ( 152)
#define COPPER_BLOCK                    ( 153)
#define DIAMOND_BLOCK                   ( 154)
#define EMERALD_BLOCK                   ( 155)
#define GOLD_BLOCK                      ( 156)
#define IRON_BLOCK                      ( 157)
#define LAPIS_LAZULI_BLOCK              ( 158)
#define LEAD_BLOCK                      ( 159)
#define MITHRIL_BLOCK                   ( 160)
#define NETHER_QUARTZ_BLOCK             ( 161)
#define NICKEL_BLOCK                    ( 162)
#define REDSTONE_BLOCK                  ( 163)
#define RUBY_BLOCK                      ( 164)
#define SAPHIRE_BLOCK                   ( 165)
#define SILVER_BLOCK                    ( 166)
#define STEEL_BLOCK                     ( 167)
#define TIN_BLOCK                       ( 168)
#define TITANIUM_BLOCK                  ( 169)
#define ANVIL                           ( 170)
#define BARREL                          ( 171)
#define BARRIER                         ( 172)
#define BELL                            ( 173)
#define BLAST_FURNACE                   ( 174)
#define BOOKSHELF                       ( 175)
#define BREWING_STAND                   ( 176)
#define CAKE                            ( 177)
#define CARTOGRAPHY_TABLE               ( 178)
#define CAULDRON                        ( 179)
#define CHAIN_COMMAND_BLOCK             ( 180)
#define CHEST                           ( 181)
#define CHIPPED_ANVIL                   ( 182)
#define COMMAND_BLOCK                   ( 183)
#define COMPOSTER                       ( 184)
#define CRAFTING_TABLE                  ( 185)
#define DAMAGED_ANVIL                   ( 186)
#define DAYLIGHT_SENSOR                 ( 187)
#define DISPENSER                       ( 188)
#define DOUBLE_CHEST                    ( 189)
#define DROPPER                         ( 190)
#define ENDER_CHEST                     ( 191)
#define ENCHANTMENT_TABLE               ( 192)
#define FLETCHING_TABLE                 ( 193)
#define FLOWER_POT                      ( 194)
#define FURNACE                         ( 195)
#define HOPPER                          ( 196)
#define JUKEBOX                         ( 197)
#define LECTURN                         ( 198)
#define NOTE_BLOCK                      ( 199)
#define OBSERVER                        ( 200)
#define PISTON                          ( 201)
#define PISTON_HEAD                     ( 202)
#define REDSTONE_LAMP                   ( 203)
#define SMITHING_TABLE                  ( 204)
#define STICKY_PISTON                   ( 205)
#define STICKY_PISTON_HEAD              ( 206)
#define TRAPPED_CHEST                   ( 207)
#define TNT                             ( 208)
#define TORCH                           ( 209)
#define REDSTONE_TORCH                  ( 210)
#define WALL_TORCH                      ( 211)
#define REDSTONE_WALL_TORCH             ( 212)
#define REDSTONE_COMPARATOR             ( 213)
#define REDSTONE_REPEATER               ( 214)
#define IRON_PRESSURE_PLATE             ( 215)
#define STONE_PRESSURE_PLATE            ( 216)
#define GOLD_PRESSURE_PLATE             ( 217)
#define RAIL                            ( 218)
#define POWERED_RAIL                    ( 219)
#define ACTIVATOR_RAIL                  ( 220)
#define DETECTOR_RAIL                   ( 221)
#define LEVER                           ( 222)
#define WOOD_BUTTON                     ( 223)
#define STONE_BUTTON                    ( 224)
#define FIRE                            ( 225)
#define TRIPWIRE                        ( 226)
#define TRIPWIRE_HOOK                   ( 227)
#define IRON_TRAPDOOR                   ( 228)
#define IRON_DOOR                       ( 229)
#define END_ROOD                        ( 230)
#define DRAGGON_EGG                     ( 231)
#define END_PORTAL_FRAME                ( 232)
#define SEA_LANTERN                     ( 233)
#define SPONGE                          ( 234)
#define WET_SPONGE                      ( 235)
#define SLIME_BLOCK                     ( 236)
#define WATER                           ( 237)
#define LAVA                            ( 238)
#define COBWEB                          ( 239)
#define LADDER                          ( 240)
#define IRON_BARS                       ( 241)
#define MONSTER_SPAWNER                 ( 242)
#define JACK_O_LANTERN                  ( 243)
#define ICE                             ( 244)
#define PACKED_ICE                      ( 245)
#define OAK_SAPLING                     ( 246)
#define OAK_LEAVES                      ( 247)
#define OAK_LOG                         ( 248)
#define OAK_STRIPPED_LOG                ( 249)
#define OAK_PLANK                       ( 250)
#define OAK_SLAB                        ( 251)
#define OAK_STAIRS                      ( 252)
#define OAK_FENCE                       ( 253)
#define OAK_FENCE_GATE                  ( 254)
#define OAK_BOAT                        ( 255)
#define OAK_DOOR                        ( 256)
#define OAK_TRAPDOOR                    ( 257)
#define OAK_PRESURE_PLATE               ( 258)
#define OAK_BUTTON                      ( 259)
#define OAK_SIGN                        ( 260)
#define BIRCH_SAPLING                   ( 261)
#define BIRCH_LEAVES                    ( 262)
#define BIRCH_LOG                       ( 263)
#define BIRCH_STRIPPED_LOG              ( 264)
#define BIRCH_PLANK                     ( 265)
#define BIRCH_STAIRS                    ( 266)
#define BIRCH_FENCE                     ( 267)
#define BIRCH_FENCE_GATE                ( 268)
#define BIRCH_BOAT                      ( 269)
#define BIRCH_DOOR                      ( 270)
#define BIRCH_TRAPDOOR                  ( 271)
#define BIRCH_PRESURE_PLATE             ( 272)
#define BIRCH_BUTTON                    ( 273)
#define BIRCH_SIGN                      ( 274)
#define SPRUCE_SAPLING                  ( 275)
#define SPRUCE_LEAVES                   ( 276)
#define SPRUCE_LOG                      ( 277)
#define SPRUCE_STRIPPED_LOG             ( 278)
#define SPRUCE_PLANK                    ( 279)
#define SPRUCE_SLAB                     ( 280)
#define SPRUCE_STAIRS                   ( 281)
#define SPRUCE_FENCE                    ( 282)
#define SPRUCE_FENCE_GATE               ( 283)
#define SPRUCE_BOAT                     ( 284)
#define SPRUCE_DOOR                     ( 285)
#define SPRUCE_TRAPDOOR                 ( 286)
#define SPRUCE_PRESURE_PLATE            ( 287)
#define SPRUCE_BUTTON                   ( 288)
#define SPRUCE_SIGN                     ( 289)
#define JUNGLE_SAPLING                  ( 290)
#define JUNGLE_LEAVES                   ( 291)
#define JUNGLE_LOG                      ( 292)
#define JUNGLE_STRIPPED_LOG             ( 293)
#define JUNGLE_PLANK                    ( 294)
#define JUNGLE_SLAB                     ( 295)
#define JUNGLE_STAIRS                   ( 296)
#define JUNGLE_FENCE                    ( 297)
#define JUNGLE_FENCE_GATE               ( 298)
#define JUNGLE_BOAT                     ( 299)
#define JUNGLE_DOOR                     ( 300)
#define JUNGLE_TRAPDOOR                 ( 301)
#define JUNGLE_PRESURE_PLATE            ( 302)
#define JUNGLE_BUTTON                   ( 303)
#define JUNGLE_SIGN                     ( 304)
#define REDWOOD_SAPLING                 ( 305)
#define REDWOOD_LEAVES                  ( 306)
#define REDWOOD_LOG                     ( 307)
#define REDWOOD_STRIPPED_LOG            ( 308)
#define REDWOOD_PLANK                   ( 309)
#define REDWOOD_SLAB                    ( 310)
#define REDWOOD_STAIRS                  ( 311)
#define REDWOOD_FENCE                   ( 312)
#define REDWOOD_FENCE_GATE              ( 313)
#define REDWOOD_BOAT                    ( 314)
#define REDWOOD_DOOR                    ( 315)
#define REDWOOD_TRAPDOOR                ( 316)
#define REDWOOD_PRESURE_PLATE           ( 317)
#define REDWOOD_BUTTON                  ( 318)
#define REDWOOD_SIGN                    ( 319)
#define ACACIA_SAPLING                  ( 320)
#define ACACIA_LEAVES                   ( 321)
#define ACACIA_LOG                      ( 322)
#define ACACIA_STRIPPED_LOG             ( 323)
#define ACACIA_PLANK                    ( 324)
#define ACACIA_SLAB                     ( 325)
#define ACACIA_STAIRS                   ( 326)
#define ACACIA_FENCE                    ( 327)
#define ACACIA_FENCE_GATE               ( 328)
#define ACACIA_BOAT                     ( 329)
#define ACACIA_DOOR                     ( 330)
#define ACACIA_TRAPDOOR                 ( 331)
#define ACACIA_PRESURE_PLATE            ( 332)
#define ACACIA_BUTTON                   ( 333)
#define ACACIA_SIGN                     ( 334)
#define DARK_OAK_SAPLING                ( 335)
#define DARK_OAK_LEAVES                 ( 336)
#define DARK_OAK_LOG                    ( 337)
#define DARK_OAK_STRIPPED_LOG           ( 338)
#define DARK_OAK_PLANK                  ( 339)
#define DARK_OAK_SLAB                   ( 340)
#define DARK_OAK_STAIRS                 ( 341)
#define DARK_OAK_FENCE                  ( 342)
#define DARK_OAK_FENCE_GATE             ( 343)
#define DARK_OAK_BOAT                   ( 344)
#define DARK_OAK_DOOR                   ( 345)
#define DARK_OAK_TRAPDOOR               ( 346)
#define DARK_OAK_PRESURE_PLATE          ( 347)
#define DARK_OAK_BUTTON                 ( 348)
#define DARK_OAK_SIGN                   ( 349)
#define BLACK_BANNER                    ( 350)
#define GRAY_BANNER                     ( 351)
#define LIGHT_GRAY_BANNER               ( 352)
#define WHITE_BANNER                    ( 353)
#define PINK_BANNER                     ( 354)
#define RED_BANNER                      ( 355)
#define ORANGE_BANNER                   ( 356)
#define YELLOW_BANNER                   ( 357)
#define LIME_BANNER                     ( 358)
#define GREEN_BANNER                    ( 359)
#define CYAN_BANNER                     ( 360)
#define LIGHT_BLUE_BANNER               ( 361)
#define BLUE_BANNER                     ( 362)
#define PURPLE_BANNER                   ( 363)
#define MAGENTA_BANNER                  ( 364)
#define BROWN_BANNER                    ( 365)
#define BLACK_BED                       ( 366)
#define GRAY_BED                        ( 367)
#define LIGHT_GRAY_BED                  ( 368)
#define WHITE_BED                       ( 369)
#define PINK_BED                        ( 370)
#define RED_BED                         ( 371)
#define ORANGE_BED                      ( 372)
#define YELLOW_BED                      ( 373)
#define LIME_BED                        ( 374)
#define GREEN_BED                       ( 375)
#define CYAN_BED                        ( 376)
#define LIGHT_BLUE_BED                  ( 377)
#define BLUE_BED                        ( 378)
#define PURPLE_BED                      ( 379)
#define MAGENTA_BED                     ( 380)
#define BROWN_BED                       ( 381)
#define BLACK_WOOL                      ( 382)
#define GRAY_WOOL                       ( 383)
#define LIGHT_GRAY_WOOL                 ( 384)
#define WHITE_WOOL                      ( 385)
#define PINK_WOOL                       ( 386)
#define RED_WOOL                        ( 387)
#define ORANGE_WOOL                     ( 388)
#define YELLOW_WOOL                     ( 389)
#define LIME_WOOL                       ( 390)
#define GREEN_WOOL                      ( 391)
#define CYAN_WOOL                       ( 392)
#define LIGHT_BLUE_WOOL                 ( 393)
#define BLUE_WOOL                       ( 394)
#define PURPLE_WOOL                     ( 395)
#define MAGENTA_WOOL                    ( 396)
#define BROWN_WOOL                      ( 397)
#define BLACK_CARPET                    ( 398)
#define GRAY_CARPET                     ( 399)
#define LIGHT_GRAY_CARPET               ( 400)
#define WHITE_CARPET                    ( 401)
#define PINK_CARPET                     ( 402)
#define RED_CARPET                      ( 403)
#define ORANGE_CARPET                   ( 404)
#define YELLOW_CARPET                   ( 405)
#define LIME_CARPET                     ( 406)
#define GREEN_CARPET                    ( 407)
#define CYAN_CARPET                     ( 408)
#define LIGHT_BLUE_CARPET               ( 409)
#define BLUE_CARPET                     ( 410)
#define PURPLE_CARPET                   ( 411)
#define MAGENTA_CARPET                  ( 412)
#define BROWN_CARPET                    ( 413)
#define BLACK_STAINED_GLASS             ( 414)
#define GRAY_STAINED_GLASS              ( 415)
#define LIGHT_GRAY_STAINED_GLASS        ( 416)
#define WHITE_STAINED_GLASS             ( 417)
#define PINK_STAINED_GLASS              ( 418)
#define RED_STAINED_GLASS               ( 419)
#define ORANGE_STAINED_GLASS            ( 420)
#define YELLOW_STAINED_GLASS            ( 421)
#define LIME_STAINED_GLASS              ( 422)
#define GREEN_STAINED_GLASS             ( 423)
#define CYAN_STAINED_GLASS              ( 424)
#define LIGHT_BLUE_STAINED_GLASS        ( 425)
#define BLUE_STAINED_GLASS              ( 426)
#define PURPLE_STAINED_GLASS            ( 427)
#define MAGENTA_STAINED_GLASS           ( 428)
#define BROWN_STAINED_GLASS             ( 429)
#define BLACK_STAINED_GLASS_PANE        ( 430)
#define GRAY_STAINED_GLASS_PANE         ( 431)
#define LIGHT_GRAY_STAINED_GLASS_PANE   ( 432)
#define WHITE_STAINED_GLASS_PANE        ( 433)
#define PINK_STAINED_GLASS_PANE         ( 434)
#define RED_STAINED_GLASS_PANE          ( 435)
#define ORANGE_STAINED_GLASS_PANE       ( 436)
#define YELLOW_STAINED_GLASS_PANE       ( 437)
#define LIME_STAINED_GLASS_PANE         ( 438)
#define GREEN_STAINED_GLASS_PANE        ( 439)
#define CYAN_STAINED_GLASS_PANE         ( 440)
#define LIGHT_BLUE_STAINED_GLASS_PANE   ( 441)
#define BLUE_STAINED_GLASS_PANE         ( 442)
#define PURPLE_STAINED_GLASS_PANE       ( 443)
#define MAGENTA_STAINED_GLASS_PANE      ( 444)
#define BROWN_STAINED_GLASS_PANE        ( 445)
#define BLACK_TERRACOTTA                ( 446)
#define GRAY_TERRACOTTA                 ( 447)
#define LIGHT_GRAY_TERRACOTTA           ( 448)
#define WHITE_TERRACOTTA                ( 449)
#define PINK_TERRACOTTA                 ( 450)
#define RED_TERRACOTTA                  ( 451)
#define ORANGE_TERRACOTTA               ( 452)
#define YELLOW_TERRACOTTA               ( 453)
#define LIME_TERRACOTTA                 ( 454)
#define GREEN_TERRACOTTA                ( 455)
#define CYAN_TERRACOTTA                 ( 456)
#define LIGHT_BLUE_TERRACOTTA           ( 457)
#define BLUE_TERRACOTTA                 ( 458)
#define PURPLE_TERRACOTTA               ( 459)
#define MAGENTA_TERRACOTTA              ( 460)
#define BROWN_TERRACOTTA                ( 461)
#define BLACK_GLAZED_TERRACOTTA         ( 462)
#define GRAY_GLAZED_TERRACOTTA          ( 463)
#define LIGHT_GRAY_GLAZED_TERRACOTTA    ( 464)
#define WHITE_GLAZED_TERRACOTTA         ( 465)
#define PINK_GLAZED_TERRACOTTA          ( 466)
#define RED_GLAZED_TERRACOTTA           ( 467)
#define ORANGE_GLAZED_TERRACOTTA        ( 468)
#define YELLOW_GLAZED_TERRACOTTA        ( 469)
#define LIME_GLAZED_TERRACOTTA          ( 470)
#define GREEN_GLAZED_TERRACOTTA         ( 471)
#define CYAN_GLAZED_TERRACOTTA          ( 472)
#define LIGHT_BLUE_GLAZED_TERRACOTTA    ( 473)
#define BLUE_GLAZED_TERRACOTTA          ( 474)
#define PURPLE_GLAZED_TERRACOTTA        ( 475)
#define MAGENTA_GLAZED_TERRACOTTA       ( 476)
#define BROWN_GLAZED_TERRACOTTA         ( 477)
#define BLACK_CONCRETE                  ( 478)
#define GRAY_CONCRETE                   ( 479)
#define LIGHT_GRAY_CONCRETE             ( 480)
#define WHITE_CONCRETE                  ( 481)
#define PINK_CONCRETE                   ( 482)
#define RED_CONCRETE                    ( 483)
#define ORANGE_CONCRETE                 ( 484)
#define YELLOW_CONCRETE                 ( 485)
#define LIME_CONCRETE                   ( 486)
#define GREEN_CONCRETE                  ( 487)
#define CYAN_CONCRETE                   ( 488)
#define LIGHT_BLUE_CONCRETE             ( 489)
#define BLUE_CONCRETE                   ( 490)
#define PURPLE_CONCRETE                 ( 491)
#define MAGENTA_CONCRETE                ( 492)
#define BROWN_CONCRETE                  ( 493)
#define BLACK_CONCRETE_POWDER           ( 494)
#define GRAY_CONCRETE_POWDER            ( 495)
#define LIGHT_GRAY_CONCRETE_POWDER      ( 496)
#define WHITE_CONCRETE_POWDER           ( 497)
#define PINK_CONCRETE_POWDER            ( 498)
#define RED_CONCRETE_POWDER             ( 499)
#define ORANGE_CONCRETE_POWDER          ( 500)
#define YELLOW_CONCRETE_POWDER          ( 501)
#define LIME_CONCRETE_POWDER            ( 502)
#define GREEN_CONCRETE_POWDER           ( 503)
#define CYAN_CONCRETE_POWDER            ( 504)
#define LIGHT_BLUE_CONCRETE_POWDER      ( 505)
#define BLUE_CONCRETE_POWDER            ( 506)
#define PURPLE_CONCRETE_POWDER          ( 507)
#define MAGENTA_CONCRETE_POWDER         ( 508)
#define BROWN_CONCRETE_POWDER           ( 509)
#define BLACK_SHULKER_BOX               ( 510)
#define GRAY_SHULKER_BOX                ( 511)
#define LIGHT_GRAY_SHULKER_BOX          ( 512)
#define WHITE_SHULKER_BOX               ( 513)
#define PINK_SHULKER_BOX                ( 514)
#define RED_SHULKER_BOX                 ( 515)
#define ORANGE_SHULKER_BOX              ( 516)
#define YELLOW_SHULKER_BOX              ( 517)
#define LIME_SHULKER_BOX                ( 518)
#define GREEN_SHULKER_BOX               ( 519)
#define CYAN_SHULKER_BOX                ( 520)
#define LIGHT_BLUE_SHULKER_BOX          ( 521)
#define BLUE_SHULKER_BOX                ( 522)
#define PURPLE_SHULKER_BOX              ( 523)
#define MAGENTA_SHULKER_BOX             ( 524)
#define BROWN_SHULKER_BOX               ( 525)
#define CRUSHED_IRON_ORE                ( 526)
#define IRON_INGOT                      ( 527)
#define IRON_NUGGET                     ( 528)
#define CRUSHED_GOLD_ORE                ( 529)
#define GOLD_INGOT                      ( 530)
#define GOLD_NUGGET                     ( 531)
#define CRUSHED_TIN_ORE                 ( 532)
#define TIN_INGOT                       ( 533)
#define TIN_NUGGET                      ( 534)
#define CRUSHED_COPPER_ORE              ( 535)
#define COPPER_INGOT                    ( 536)
#define COPPER_NUGGET                   ( 537)
#define CRUSHED_LEAD_ORE                ( 538)
#define LEAD_INGOT                      ( 539)
#define LEAD_NUGGET                     ( 540)
#define CRUSHED_ALUMINUM_ORE            ( 541)
#define ALUMINUM_INGOT                  ( 542)
#define ALUMINUM_NUGGET                 ( 543)
#define CRUSHED_NICKEL_ORE              ( 544)
#define NICKEL_INGOT                    ( 545)
#define NICKEL_NUGGET                   ( 546)
#define CRUSHED_SILVER_ORE              ( 547)
#define SILVER_INGOT                    ( 548)
#define SILVER_NUGGET                   ( 549)
#define CRUSHED_TITANIUM_ORE            ( 550)
#define TITANIUM_INGOT                  ( 551)
#define TITANIUM_NUGGET                 ( 552)
#define CRUSHED_MITHRIL_ORE             ( 553)
#define MITHRIL_INGOT                   ( 554)
#define MITHRIL_NUGGET                  ( 555)
#define BRONZE_INGOT                    ( 556)
#define BRONZE_NUGGET                   ( 557)
#define STEEL_INGOT                     ( 558)
#define STEEL_NUGGET                    ( 559)
#define COAL                            ( 560)
#define REDSTONE_DUST                   ( 561)
#define LAPIS_LAZULI                    ( 562)
#define EMERALD                         ( 563)
#define DIAMOND                         ( 564)
#define RUBY                            ( 565)
#define SAPHIRE                         ( 566)
#define NETHER_QUARTZ                   ( 567)
#define NETHER_BRICK                    ( 568)
#define RED_NETHER_BRICK                ( 569)
#define GLOWSTONE_DUST                  ( 570)
#define CHARCOAL                        ( 571)
#define BRICK                           ( 572)
#define CLAY_BALL                       ( 573)
#define WOODEN_SWORD                    ( 574)
#define WOODEN_AXE                      ( 575)
#define WOODEN_SHOVEL                   ( 576)
#define WOODEN_PICKAXE                  ( 577)
#define WOODEN_HOE                      ( 578)
#define STONE_SWORD                     ( 579)
#define STONE_AXE                       ( 580)
#define STONE_SHOVEL                    ( 581)
#define STONE_PICKAXE                   ( 582)
#define STONE_HOE                       ( 583)
#define IRON_SWORD                      ( 584)
#define IRON_AXE                        ( 585)
#define IRON_SHOVEL                     ( 586)
#define IRON_PICKAXE                    ( 587)
#define IRON_HOE                        ( 588)
#define STEEL_SWORD                     ( 589)
#define STEEL_AXE                       ( 590)
#define STEEL_SHOVEL                    ( 591)
#define STEEL_PICKAXE                   ( 592)
#define STEEL_HOE                       ( 593)
#define DIAMOND_SWORD                   ( 594)
#define DIAMOND_AXE                     ( 595)
#define DIAMOND_SHOVEL                  ( 596)
#define DIAMOND_PICKAXE                 ( 597)
#define DIAMOND_HOE                     ( 598)
#define WOODEN_SHEILD                   ( 599)
#define IRON_SHEILD                     ( 600)
#define TITANIUM_SHEILD                 ( 601)
#define BUCKET                          ( 602)
#define ROPE                            ( 603)
#define BOW                             ( 604)
#define FISHING_ROD                     ( 605)
#define SHEARS                          ( 606)
#define FINT_AND_STEEL                  ( 607)
#define BONEMEAL                        ( 608)
#define LEATHER_CAP                     ( 609)
#define LEATHER_VEST                    ( 610)
#define LEATHER_PANTS                   ( 611)
#define LEATHER_STOCKINGS               ( 612)
#define CHAINMAIL_CAP                   ( 613)
#define CHAINMAIL_VEST                  ( 614)
#define CHAINMAIL_PANTS                 ( 615)
#define CHAINMAIL_STOCKINGS             ( 616)
#define MITHRIL_CAP                     ( 617)
#define MITHRIL_VEST                    ( 618)
#define MITHRIL_PANTS                   ( 619)
#define MITHRIL_STOCKINGS               ( 620)
#define IRON_HELMET                     ( 621)
#define IRON_CHESTPLATE                 ( 622)
#define IRON_LEGGINGS                   ( 623)
#define IRON_BOOTS                      ( 624)
#define STEEL_HELMET                    ( 625)
#define STEEL_CHESTPLATE                ( 626)
#define STEEL_LEGGINGS                  ( 627)
#define STEEL_BOOTS                     ( 628)
#define DIAMOND_HELMET                  ( 629)
#define DIAMOND_CHESTPLATE              ( 630)
#define DIAMOND_LEGGINGS                ( 631)
#define DIAMOND_BOOTS                   ( 632)
#define TITANIUM_HELMET                 ( 633)
#define TITANIUM_CHESTPLATE             ( 634)
#define TITANIUM_LEGGINGS               ( 635)
#define TITANIUM_BOOTS                  ( 636)
#define RAW_BEEF                        ( 637)
#define STEAK                           ( 638)
#define RAW_MUTTON                      ( 639)
#define COOKED_MUTTON                   ( 640)
#define RAW_CHICKEN                     ( 641)
#define COOKED_CHICKEN                  ( 642)
#define RAW_PORKCHOP                    ( 643)
#define COOKED_PORKCHOP                 ( 644)
#define RAW_RABBIT                      ( 645)
#define COOKED_RABBIT                   ( 646)
#define RAW_SALMON                      ( 647)
#define COOKED_SALMON                   ( 648)
#define RAW_COD                         ( 649)
#define COOKED_COD                      ( 650)
#define RAW_TUNA                        ( 651)
#define COOKED_TUNA                     ( 652)
#define RAW_BASS                        ( 653)
#define COOKED_BASS                     ( 654)
#define APPLE                           ( 655)
#define BEETROOT_SEEDS                  ( 656)
#define BEETROOT_PLANT                  ( 657)
#define BEETROOT                        ( 658)
#define BERRY_BUSH                      ( 659)
#define BERRIES                         ( 660)
#define BROWN_MUSHROOM                  ( 661)
#define CARROT_PLANT                    ( 662)
#define CARROT                          ( 663)
#define MELLON_STEM                     ( 664)
#define MELLON                          ( 665)
#define MELLON_WEDGE                    ( 666)
#define POTATO_PLANT                    ( 667)
#define POTATO                          ( 668)
#define PUMPKIN_STEM                    ( 669)
#define PUMPKIN                         ( 670)
#define RED_MUSHROOM                    ( 671)
#define SUGAR_CANES                     ( 672)
#define SUGAR                           ( 673)
#define WHEAT_SEEDS                     ( 674)
#define WHEAT_PLANT                     ( 675)
#define WHEAT                           ( 676)
#define BAMBOO                          ( 677)
#define CACTUS                          ( 678)
#define DEAD_BRUSH                      ( 679)
#define DRY_REEDS                       ( 680)
#define FERN                            ( 681)
#define GRASS                           ( 682)
#define KELP                            ( 683)
#define LILY_PAD                        ( 684)
#define SEAGRASS                        ( 685)
#define SWEET_BERRY_BUSH                ( 686)
#define TALL_FERN                       ( 687)
#define TALL_GRASS                      ( 688)
#define TALL_SEAGRASS                   ( 689)
#define VINES                           ( 690)
#define ALLIUM                          ( 691)
#define AZURE_BLUET                     ( 692)
#define BLUE_ORCHID                     ( 693)
#define DANDELION                       ( 694)
#define LILAC                           ( 695)
#define ORANGE_TULIP                    ( 696)
#define OXEYE_DAISY                     ( 697)
#define PEONY                           ( 698)
#define PINK_TULIP                      ( 699)
#define POPPY                           ( 700)
#define RED_TULIP                       ( 701)
#define ROSE_BUSH                       ( 702)
#define SUNFLOWER                       ( 703)
#define WHITE_TULIP                     ( 704)



#endif



