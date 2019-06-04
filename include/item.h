/*
    Copyright 2019 Wesley Dahar

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
#ifndef ITEM_H
#define ITEM_H

#include "common.h"



#define ITEM_ID   (20U)      // item >> ITEM_ID
#define ITEM_TAG  (0xFFFU)   // item & ITEM_TAG
#define ITEM_DATA (0xFF000U) // item & ITEM_DATA



typedef uint32_t Item;



typedef struct {
    char *name;
    char *lore;
    uint8_t stackSize;
    uint8_t fuelValue;
    uint8_t foodValue;
    uint8_t damageValue;
    uint8_t healthValue;
} ItemMeta;



// Handlers
bool use_item_handler(Item *tool);
bool begin_attack_item_handler(Item *tool);
bool end_attack_item_handler(Item *tool);



// Object Lifecycle
Item *create_item(uint16_t itemID);
void free_item(Item *item);
void read_item(Item *item, FILE *file);
void write_item(Item *item, FILE *file);



// Global ItemMetas
// Blocks listed first so defines may be used for both Item and BlockMetas
const ItemMeta itemMetas[] = {
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



#define ID_AIR                             (   0)
#define ID_STONE                           (   1)
#define ID_STONE_SLAB                      (   2)
#define ID_STONE_STAIRS                    (   3)
#define ID_SMOOTH_STONE                    (   4)
#define ID_SMOOTH_STONE_SLAB               (   5)
#define ID_SMOOTH_STONE_STAIRS             (   6)
#define ID_STONE_BRICKS                    (   7)
#define ID_STONE_BRICK_SLAB                (   8)
#define ID_STONE_BRICK_STAIRS              (   9)
#define ID_STONE_BRICK_WALL                (  10)
#define ID_CHISELED_STONE_BRICKS           (  11)
#define ID_CRACKED_STONE_BRICKS            (  12)
#define ID_CRACKED_STONE_BRICK_SLAB        (  13)
#define ID_CRACKED_STONE_BRICK_STAIRS      (  14)
#define ID_CRACKED_STONE_BRICK_WALL        (  15)
#define ID_MOSSY_STONE_BRICKS              (  16)
#define ID_MOSSY_STONE_BRICK_SLAB          (  17)
#define ID_MOSSY_STONE_BRICK_STAIRS        (  18)
#define ID_MOSSY_STONE_BRICK_WALL          (  19)
#define ID_COBBLESTONE                     (  20)
#define ID_COBBLESTONE_SLAB                (  21)
#define ID_COBBLESTONE_STAIRS              (  22)
#define ID_COBBLESTONE_WALL                (  23)
#define ID_MOSSY_COBBLESTONE               (  24)
#define ID_MOSSY_COBBLESTONE_SLAB          (  25)
#define ID_MOSSY_COBBLESTONE_STAIRS        (  26)
#define ID_MOSSY_COBBLESTONE_WALL          (  27)
#define ID_ANDESITE                        (  28)
#define ID_ANDESITE_SLAB                   (  29)
#define ID_ANDESITE_STAIRS                 (  30)
#define ID_ANDESITE_WALL                   (  31)
#define ID_POLISHED_ANDESITE               (  32)
#define ID_POLISHED_ANDESITE_SLAB          (  33)
#define ID_POLISHED_ANDESITE_STAIRS        (  34)
#define ID_DIORITE                         (  35)
#define ID_DIORITE_SLAB                    (  36)
#define ID_DIORITE_STAIRS                  (  37)
#define ID_DIORITE_WALL                    (  38)
#define ID_POLISHED_DIORITE                (  39)
#define ID_POLISHED_DIORITE_SLAB           (  40)
#define ID_POLISHED_DIORITE_STAIRS         (  41)
#define ID_GRANITE                         (  42)
#define ID_GRANITE_SLAB                    (  43)
#define ID_GRANITE_STAIRS                  (  44)
#define ID_GRANITE_WALL                    (  45)
#define ID_POLISHED_GRANITE                (  46)
#define ID_POLISHED_GRANITE_SLAB           (  47)
#define ID_POLISHED_GRANITE_STAIRS         (  48)
#define ID_MARBLE                          (  49)
#define ID_MARBLE_SLAB                     (  50)
#define ID_MARBLE_STAIRS                   (  51)
#define ID_MARBLE_WALL                     (  52)
#define ID_MARBLE_PILLAR                   (  53)
#define ID_CHISELED_MARBLE                 (  54)
#define ID_POLISHED_MARBLE                 (  55)
#define ID_POLISHED_MARBLE_SLAB            (  56)
#define ID_POLISHED_MARBLE_STAIRS          (  57)
#define ID_FLAGSTONE                       (  58)
#define ID_FLAGSTONE_SLAB                  (  59)
#define ID_FLAGSTONE_STAIRS                (  60)
#define ID_FLAGSTONE_WALL                  (  61)
#define ID_LIMESTONE                       (  62)
#define ID_CRUSHED_LIMESTONE               (  63)
#define ID_END_STONE                       (  64)
#define ID_END_STONE_BRICKS                (  65)
#define ID_END_STONE_BRICK_SLAB            (  66)
#define ID_END_STONE_BRICK_STAIRS          (  67)
#define ID_END_STONE_BRICK_WALL            (  68)
#define ID_BRICKS                          (  69)
#define ID_BRICK_SLAB                      (  70)
#define ID_BRICK_STAIRS                    (  71)
#define ID_BRICK_WALL                      (  72)
#define ID_SANDSTONE                       (  73)
#define ID_SANDSTONE_SLAB                  (  74)
#define ID_SANDSTONE_STAIRS                (  75)
#define ID_SANDSTONE_WALL                  (  76)
#define ID_CHISELED_SANDSTONE              (  77)
#define ID_SMOOTH_SANDSTONE                (  78)
#define ID_SMOOTH_SANDSTONE_SLAB           (  79)
#define ID_SMOOTH_SANDSTONE_STAIRS         (  80)
#define ID_CUT_SANDSTONE                   (  81)
#define ID_CUT_SANDSTONE_SLAB              (  82)
#define ID_RED_SANDSTONE                   (  83)
#define ID_RED_SANDSTONE_SLAB              (  84)
#define ID_RED_SANDSTONE_STAIRS            (  85)
#define ID_RED_SANDSTONE_WALL              (  86)
#define ID_CHISELED_RED_SANDSTONE          (  87)
#define ID_SMOOTH_RED_SANDSTONE            (  88)
#define ID_SMOOTH_RED_SANDSTONE_SLAB       (  89)
#define ID_SMOOTH_RED_SANDSTONE_STAIRS     (  90)
#define ID_CUT_RED_SANDSTONE               (  91)
#define ID_CUT_RED_SANDSTONE_SLAB          (  92)
#define ID_QUARTZ_BLOCK                    (  93)
#define ID_QUARTZ_SLAB                     (  94)
#define ID_QUARTZ_STAIRS                   (  95)
#define ID_QUARTZ_PILLAR                   (  96)
#define ID_CHISELED_QUARTZ                 (  97)
#define ID_NETHER_BRICKS                   (  98)
#define ID_NETHER_BRICK_SLAB               (  99)
#define ID_NETHER_BRICK_STAIRS             ( 100)
#define ID_NETHER_BRICK_FENCE              ( 101)
#define ID_RED_NETHER_BRICKS               ( 102)
#define ID_RED_NETHER_BRICK_SLAB           ( 103)
#define ID_RED_NETHER_BRICK_STAIRS         ( 104)
#define ID_RED_NETHER_BRICK_FENCE          ( 105)
#define ID_PRISMARINE                      ( 106)
#define ID_PRISMARINE_BRICKS               ( 107)
#define ID_DARK_PRISMARINE                 ( 108)
#define ID_DIRT                            ( 109)
#define ID_GRASS_BLOCK                     ( 110)
#define ID_GRASS_PATH                      ( 111)
#define ID_FARMLAND                        ( 112)
#define ID_PODZOL                          ( 113)
#define ID_MYCELIUM                        ( 114)
#define ID_COARSE_DIRT                     ( 115)
#define ID_GRAVEL                          ( 116)
#define ID_SAND                            ( 117)
#define ID_RED_SAND                        ( 118)
#define ID_GLASS                           ( 119)
#define ID_GLASS_PANE                      ( 120)
#define ID_SNOW_LAYER                      ( 121)
#define ID_SNOW_BLOCK                      ( 122)
#define ID_CLAY                            ( 123)
#define ID_TERRACOTTA                      ( 124)
#define ID_OBSIDIAN                        ( 125)
#define ID_BEDROCK                         ( 126)
#define ID_NETHERRACK                      ( 127)
#define ID_SOUL_SAND                       ( 128)
#define ID_MAGMA_BLOCK                     ( 129)
#define ID_GLOWSTONE                       ( 130)
#define ID_ALUMINUM_ORE                    ( 131)
#define ID_COAL_ORE                        ( 132)
#define ID_COPPER_ORE                      ( 133)
#define ID_DIAMOND_ORE                     ( 134)
#define ID_EMERALD_ORE                     ( 135)
#define ID_GOLD_ORE                        ( 136)
#define ID_IRON_ORE                        ( 137)
#define ID_LAPIS_LAZULI_ORE                ( 138)
#define ID_LEAD_ORE                        ( 139)
#define ID_MITHRIL_ORE                     ( 140)
#define ID_NETHER_QUARTZ_ORE               ( 141)
#define ID_NICKEL_ORE                      ( 142)
#define ID_REDSTONE_ORE                    ( 143)
#define ID_RUBY_ORE                        ( 144)
#define ID_SAPHIRE_ORE                     ( 145)
#define ID_SILVER_ORE                      ( 146)
#define ID_TIN_ORE                         ( 147)
#define ID_TITANIUM_ORE                    ( 148)
#define ID_ALUMINUM_BLOCK                  ( 149)
#define ID_BRONZE_BLOCK                    ( 150)
#define ID_CHARCOAL_BLOCK                  ( 151)
#define ID_COAL_BLOCK                      ( 152)
#define ID_COPPER_BLOCK                    ( 153)
#define ID_DIAMOND_BLOCK                   ( 154)
#define ID_EMERALD_BLOCK                   ( 155)
#define ID_GOLD_BLOCK                      ( 156)
#define ID_IRON_BLOCK                      ( 157)
#define ID_LAPIS_LAZULI_BLOCK              ( 158)
#define ID_LEAD_BLOCK                      ( 159)
#define ID_MITHRIL_BLOCK                   ( 160)
#define ID_NETHER_QUARTZ_BLOCK             ( 161)
#define ID_NICKEL_BLOCK                    ( 162)
#define ID_REDSTONE_BLOCK                  ( 163)
#define ID_RUBY_BLOCK                      ( 164)
#define ID_SAPHIRE_BLOCK                   ( 165)
#define ID_SILVER_BLOCK                    ( 166)
#define ID_STEEL_BLOCK                     ( 167)
#define ID_TIN_BLOCK                       ( 168)
#define ID_TITANIUM_BLOCK                  ( 169)
#define ID_ANVIL                           ( 170)
#define ID_BARREL                          ( 171)
#define ID_BARRIER                         ( 172)
#define ID_BELL                            ( 173)
#define ID_BLAST_FURNACE                   ( 174)
#define ID_BOOKSHELF                       ( 175)
#define ID_BREWING_STAND                   ( 176)
#define ID_CAKE                            ( 177)
#define ID_CARTOGRAPHY_TABLE               ( 178)
#define ID_CAULDRON                        ( 179)
#define ID_CHAIN_COMMAND_BLOCK             ( 180)
#define ID_CHEST                           ( 181)
#define ID_CHIPPED_ANVIL                   ( 182)
#define ID_COMMAND_BLOCK                   ( 183)
#define ID_COMPOSTER                       ( 184)
#define ID_CRAFTING_TABLE                  ( 185)
#define ID_DAMAGED_ANVIL                   ( 186)
#define ID_DAYLIGHT_SENSOR                 ( 187)
#define ID_DISPENSER                       ( 188)
#define ID_DOUBLE_CHEST                    ( 189)
#define ID_DROPPER                         ( 190)
#define ID_ENDER_CHEST                     ( 191)
#define ID_ENCHANTMENT_TABLE               ( 192)
#define ID_FLETCHING_TABLE                 ( 193)
#define ID_FLOWER_POT                      ( 194)
#define ID_FURNACE                         ( 195)
#define ID_HOPPER                          ( 196)
#define ID_JUKEBOX                         ( 197)
#define ID_LECTURN                         ( 198)
#define ID_NOTE_BLOCK                      ( 199)
#define ID_OBSERVER                        ( 200)
#define ID_PISTON                          ( 201)
#define ID_PISTON_HEAD                     ( 202)
#define ID_REDSTONE_LAMP                   ( 203)
#define ID_SMITHING_TABLE                  ( 204)
#define ID_STICKY_PISTON                   ( 205)
#define ID_STICKY_PISTON_HEAD              ( 206)
#define ID_TRAPPED_CHEST                   ( 207)
#define ID_TNT                             ( 208)
#define ID_TORCH                           ( 209)
#define ID_REDSTONE_TORCH                  ( 210)
#define ID_WALL_TORCH                      ( 211)
#define ID_REDSTONE_WALL_TORCH             ( 212)
#define ID_REDSTONE_COMPARATOR             ( 213)
#define ID_REDSTONE_REPEATER               ( 214)
#define ID_IRON_PRESSURE_PLATE             ( 215)
#define ID_STONE_PRESSURE_PLATE            ( 216)
#define ID_GOLD_PRESSURE_PLATE             ( 217)
#define ID_RAIL                            ( 218)
#define ID_POWERED_RAIL                    ( 219)
#define ID_ACTIVATOR_RAIL                  ( 220)
#define ID_DETECTOR_RAIL                   ( 221)
#define ID_LEVER                           ( 222)
#define ID_WOOD_BUTTON                     ( 223)
#define ID_STONE_BUTTON                    ( 224)
#define ID_FIRE                            ( 225)
#define ID_TRIPWIRE                        ( 226)
#define ID_TRIPWIRE_HOOK                   ( 227)
#define ID_IRON_TRAPDOOR                   ( 228)
#define ID_IRON_DOOR                       ( 229)
#define ID_END_ROOD                        ( 230)
#define ID_DRAGGON_EGG                     ( 231)
#define ID_END_PORTAL_FRAME                ( 232)
#define ID_SEA_LANTERN                     ( 233)
#define ID_SPONGE                          ( 234)
#define ID_WET_SPONGE                      ( 235)
#define ID_SLIME_BLOCK                     ( 236)
#define ID_WATER                           ( 237)
#define ID_LAVA                            ( 238)
#define ID_COBWEB                          ( 239)
#define ID_LADDER                          ( 240)
#define ID_IRON_BARS                       ( 241)
#define ID_MONSTER_SPAWNER                 ( 242)
#define ID_JACK_O_LANTERN                  ( 243)
#define ID_ICE                             ( 244)
#define ID_PACKED_ICE                      ( 245)
#define ID_OAK_SAPLING                     ( 246)
#define ID_OAK_LEAVES                      ( 247)
#define ID_OAK_LOG                         ( 248)
#define ID_OAK_STRIPPED_LOG                ( 249)
#define ID_OAK_PLANK                       ( 250)
#define ID_OAK_SLAB                        ( 251)
#define ID_OAK_STAIRS                      ( 252)
#define ID_OAK_FENCE                       ( 253)
#define ID_OAK_FENCE_GATE                  ( 254)
#define ID_OAK_BOAT                        ( 255)
#define ID_OAK_DOOR                        ( 256)
#define ID_OAK_TRAPDOOR                    ( 257)
#define ID_OAK_PRESURE_PLATE               ( 258)
#define ID_OAK_BUTTON                      ( 259)
#define ID_OAK_SIGN                        ( 260)
#define ID_BIRCH_SAPLING                   ( 261)
#define ID_BIRCH_LEAVES                    ( 262)
#define ID_BIRCH_LOG                       ( 263)
#define ID_BIRCH_STRIPPED_LOG              ( 264)
#define ID_BIRCH_PLANK                     ( 265)
#define ID_BIRCH_STAIRS                    ( 266)
#define ID_BIRCH_FENCE                     ( 267)
#define ID_BIRCH_FENCE_GATE                ( 268)
#define ID_BIRCH_BOAT                      ( 269)
#define ID_BIRCH_DOOR                      ( 270)
#define ID_BIRCH_TRAPDOOR                  ( 271)
#define ID_BIRCH_PRESURE_PLATE             ( 272)
#define ID_BIRCH_BUTTON                    ( 273)
#define ID_BIRCH_SIGN                      ( 274)
#define ID_SPRUCE_SAPLING                  ( 275)
#define ID_SPRUCE_LEAVES                   ( 276)
#define ID_SPRUCE_LOG                      ( 277)
#define ID_SPRUCE_STRIPPED_LOG             ( 278)
#define ID_SPRUCE_PLANK                    ( 279)
#define ID_SPRUCE_SLAB                     ( 280)
#define ID_SPRUCE_STAIRS                   ( 281)
#define ID_SPRUCE_FENCE                    ( 282)
#define ID_SPRUCE_FENCE_GATE               ( 283)
#define ID_SPRUCE_BOAT                     ( 284)
#define ID_SPRUCE_DOOR                     ( 285)
#define ID_SPRUCE_TRAPDOOR                 ( 286)
#define ID_SPRUCE_PRESURE_PLATE            ( 287)
#define ID_SPRUCE_BUTTON                   ( 288)
#define ID_SPRUCE_SIGN                     ( 289)
#define ID_JUNGLE_SAPLING                  ( 290)
#define ID_JUNGLE_LEAVES                   ( 291)
#define ID_JUNGLE_LOG                      ( 292)
#define ID_JUNGLE_STRIPPED_LOG             ( 293)
#define ID_JUNGLE_PLANK                    ( 294)
#define ID_JUNGLE_SLAB                     ( 295)
#define ID_JUNGLE_STAIRS                   ( 296)
#define ID_JUNGLE_FENCE                    ( 297)
#define ID_JUNGLE_FENCE_GATE               ( 298)
#define ID_JUNGLE_BOAT                     ( 299)
#define ID_JUNGLE_DOOR                     ( 300)
#define ID_JUNGLE_TRAPDOOR                 ( 301)
#define ID_JUNGLE_PRESURE_PLATE            ( 302)
#define ID_JUNGLE_BUTTON                   ( 303)
#define ID_JUNGLE_SIGN                     ( 304)
#define ID_REDWOOD_SAPLING                 ( 305)
#define ID_REDWOOD_LEAVES                  ( 306)
#define ID_REDWOOD_LOG                     ( 307)
#define ID_REDWOOD_STRIPPED_LOG            ( 308)
#define ID_REDWOOD_PLANK                   ( 309)
#define ID_REDWOOD_SLAB                    ( 310)
#define ID_REDWOOD_STAIRS                  ( 311)
#define ID_REDWOOD_FENCE                   ( 312)
#define ID_REDWOOD_FENCE_GATE              ( 313)
#define ID_REDWOOD_BOAT                    ( 314)
#define ID_REDWOOD_DOOR                    ( 315)
#define ID_REDWOOD_TRAPDOOR                ( 316)
#define ID_REDWOOD_PRESURE_PLATE           ( 317)
#define ID_REDWOOD_BUTTON                  ( 318)
#define ID_REDWOOD_SIGN                    ( 319)
#define ID_ACACIA_SAPLING                  ( 320)
#define ID_ACACIA_LEAVES                   ( 321)
#define ID_ACACIA_LOG                      ( 322)
#define ID_ACACIA_STRIPPED_LOG             ( 323)
#define ID_ACACIA_PLANK                    ( 324)
#define ID_ACACIA_SLAB                     ( 325)
#define ID_ACACIA_STAIRS                   ( 326)
#define ID_ACACIA_FENCE                    ( 327)
#define ID_ACACIA_FENCE_GATE               ( 328)
#define ID_ACACIA_BOAT                     ( 329)
#define ID_ACACIA_DOOR                     ( 330)
#define ID_ACACIA_TRAPDOOR                 ( 331)
#define ID_ACACIA_PRESURE_PLATE            ( 332)
#define ID_ACACIA_BUTTON                   ( 333)
#define ID_ACACIA_SIGN                     ( 334)
#define ID_DARK_OAK_SAPLING                ( 335)
#define ID_DARK_OAK_LEAVES                 ( 336)
#define ID_DARK_OAK_LOG                    ( 337)
#define ID_DARK_OAK_STRIPPED_LOG           ( 338)
#define ID_DARK_OAK_PLANK                  ( 339)
#define ID_DARK_OAK_SLAB                   ( 340)
#define ID_DARK_OAK_STAIRS                 ( 341)
#define ID_DARK_OAK_FENCE                  ( 342)
#define ID_DARK_OAK_FENCE_GATE             ( 343)
#define ID_DARK_OAK_BOAT                   ( 344)
#define ID_DARK_OAK_DOOR                   ( 345)
#define ID_DARK_OAK_TRAPDOOR               ( 346)
#define ID_DARK_OAK_PRESURE_PLATE          ( 347)
#define ID_DARK_OAK_BUTTON                 ( 348)
#define ID_DARK_OAK_SIGN                   ( 349)
#define ID_BLACK_BANNER                    ( 350)
#define ID_GRAY_BANNER                     ( 351)
#define ID_LIGHT_GRAY_BANNER               ( 352)
#define ID_WHITE_BANNER                    ( 353)
#define ID_PINK_BANNER                     ( 354)
#define ID_RED_BANNER                      ( 355)
#define ID_ORANGE_BANNER                   ( 356)
#define ID_YELLOW_BANNER                   ( 357)
#define ID_LIME_BANNER                     ( 358)
#define ID_GREEN_BANNER                    ( 359)
#define ID_CYAN_BANNER                     ( 360)
#define ID_LIGHT_BLUE_BANNER               ( 361)
#define ID_BLUE_BANNER                     ( 362)
#define ID_PURPLE_BANNER                   ( 363)
#define ID_MAGENTA_BANNER                  ( 364)
#define ID_BROWN_BANNER                    ( 365)
#define ID_BLACK_BED                       ( 366)
#define ID_GRAY_BED                        ( 367)
#define ID_LIGHT_GRAY_BED                  ( 368)
#define ID_WHITE_BED                       ( 369)
#define ID_PINK_BED                        ( 370)
#define ID_RED_BED                         ( 371)
#define ID_ORANGE_BED                      ( 372)
#define ID_YELLOW_BED                      ( 373)
#define ID_LIME_BED                        ( 374)
#define ID_GREEN_BED                       ( 375)
#define ID_CYAN_BED                        ( 376)
#define ID_LIGHT_BLUE_BED                  ( 377)
#define ID_BLUE_BED                        ( 378)
#define ID_PURPLE_BED                      ( 379)
#define ID_MAGENTA_BED                     ( 380)
#define ID_BROWN_BED                       ( 381)
#define ID_BLACK_WOOL                      ( 382)
#define ID_GRAY_WOOL                       ( 383)
#define ID_LIGHT_GRAY_WOOL                 ( 384)
#define ID_WHITE_WOOL                      ( 385)
#define ID_PINK_WOOL                       ( 386)
#define ID_RED_WOOL                        ( 387)
#define ID_ORANGE_WOOL                     ( 388)
#define ID_YELLOW_WOOL                     ( 389)
#define ID_LIME_WOOL                       ( 390)
#define ID_GREEN_WOOL                      ( 391)
#define ID_CYAN_WOOL                       ( 392)
#define ID_LIGHT_BLUE_WOOL                 ( 393)
#define ID_BLUE_WOOL                       ( 394)
#define ID_PURPLE_WOOL                     ( 395)
#define ID_MAGENTA_WOOL                    ( 396)
#define ID_BROWN_WOOL                      ( 397)
#define ID_BLACK_CARPET                    ( 398)
#define ID_GRAY_CARPET                     ( 399)
#define ID_LIGHT_GRAY_CARPET               ( 400)
#define ID_WHITE_CARPET                    ( 401)
#define ID_PINK_CARPET                     ( 402)
#define ID_RED_CARPET                      ( 403)
#define ID_ORANGE_CARPET                   ( 404)
#define ID_YELLOW_CARPET                   ( 405)
#define ID_LIME_CARPET                     ( 406)
#define ID_GREEN_CARPET                    ( 407)
#define ID_CYAN_CARPET                     ( 408)
#define ID_LIGHT_BLUE_CARPET               ( 409)
#define ID_BLUE_CARPET                     ( 410)
#define ID_PURPLE_CARPET                   ( 411)
#define ID_MAGENTA_CARPET                  ( 412)
#define ID_BROWN_CARPET                    ( 413)
#define ID_BLACK_STAINED_GLASS             ( 414)
#define ID_GRAY_STAINED_GLASS              ( 415)
#define ID_LIGHT_GRAY_STAINED_GLASS        ( 416)
#define ID_WHITE_STAINED_GLASS             ( 417)
#define ID_PINK_STAINED_GLASS              ( 418)
#define ID_RED_STAINED_GLASS               ( 419)
#define ID_ORANGE_STAINED_GLASS            ( 420)
#define ID_YELLOW_STAINED_GLASS            ( 421)
#define ID_LIME_STAINED_GLASS              ( 422)
#define ID_GREEN_STAINED_GLASS             ( 423)
#define ID_CYAN_STAINED_GLASS              ( 424)
#define ID_LIGHT_BLUE_STAINED_GLASS        ( 425)
#define ID_BLUE_STAINED_GLASS              ( 426)
#define ID_PURPLE_STAINED_GLASS            ( 427)
#define ID_MAGENTA_STAINED_GLASS           ( 428)
#define ID_BROWN_STAINED_GLASS             ( 429)
#define ID_BLACK_STAINED_GLASS_PANE        ( 430)
#define ID_GRAY_STAINED_GLASS_PANE         ( 431)
#define ID_LIGHT_GRAY_STAINED_GLASS_PANE   ( 432)
#define ID_WHITE_STAINED_GLASS_PANE        ( 433)
#define ID_PINK_STAINED_GLASS_PANE         ( 434)
#define ID_RED_STAINED_GLASS_PANE          ( 435)
#define ID_ORANGE_STAINED_GLASS_PANE       ( 436)
#define ID_YELLOW_STAINED_GLASS_PANE       ( 437)
#define ID_LIME_STAINED_GLASS_PANE         ( 438)
#define ID_GREEN_STAINED_GLASS_PANE        ( 439)
#define ID_CYAN_STAINED_GLASS_PANE         ( 440)
#define ID_LIGHT_BLUE_STAINED_GLASS_PANE   ( 441)
#define ID_BLUE_STAINED_GLASS_PANE         ( 442)
#define ID_PURPLE_STAINED_GLASS_PANE       ( 443)
#define ID_MAGENTA_STAINED_GLASS_PANE      ( 444)
#define ID_BROWN_STAINED_GLASS_PANE        ( 445)
#define ID_BLACK_TERRACOTTA                ( 446)
#define ID_GRAY_TERRACOTTA                 ( 447)
#define ID_LIGHT_GRAY_TERRACOTTA           ( 448)
#define ID_WHITE_TERRACOTTA                ( 449)
#define ID_PINK_TERRACOTTA                 ( 450)
#define ID_RED_TERRACOTTA                  ( 451)
#define ID_ORANGE_TERRACOTTA               ( 452)
#define ID_YELLOW_TERRACOTTA               ( 453)
#define ID_LIME_TERRACOTTA                 ( 454)
#define ID_GREEN_TERRACOTTA                ( 455)
#define ID_CYAN_TERRACOTTA                 ( 456)
#define ID_LIGHT_BLUE_TERRACOTTA           ( 457)
#define ID_BLUE_TERRACOTTA                 ( 458)
#define ID_PURPLE_TERRACOTTA               ( 459)
#define ID_MAGENTA_TERRACOTTA              ( 460)
#define ID_BROWN_TERRACOTTA                ( 461)
#define ID_BLACK_GLAZED_TERRACOTTA         ( 462)
#define ID_GRAY_GLAZED_TERRACOTTA          ( 463)
#define ID_LIGHT_GRAY_GLAZED_TERRACOTTA    ( 464)
#define ID_WHITE_GLAZED_TERRACOTTA         ( 465)
#define ID_PINK_GLAZED_TERRACOTTA          ( 466)
#define ID_RED_GLAZED_TERRACOTTA           ( 467)
#define ID_ORANGE_GLAZED_TERRACOTTA        ( 468)
#define ID_YELLOW_GLAZED_TERRACOTTA        ( 469)
#define ID_LIME_GLAZED_TERRACOTTA          ( 470)
#define ID_GREEN_GLAZED_TERRACOTTA         ( 471)
#define ID_CYAN_GLAZED_TERRACOTTA          ( 472)
#define ID_LIGHT_BLUE_GLAZED_TERRACOTTA    ( 473)
#define ID_BLUE_GLAZED_TERRACOTTA          ( 474)
#define ID_PURPLE_GLAZED_TERRACOTTA        ( 475)
#define ID_MAGENTA_GLAZED_TERRACOTTA       ( 476)
#define ID_BROWN_GLAZED_TERRACOTTA         ( 477)
#define ID_BLACK_CONCRETE                  ( 478)
#define ID_GRAY_CONCRETE                   ( 479)
#define ID_LIGHT_GRAY_CONCRETE             ( 480)
#define ID_WHITE_CONCRETE                  ( 481)
#define ID_PINK_CONCRETE                   ( 482)
#define ID_RED_CONCRETE                    ( 483)
#define ID_ORANGE_CONCRETE                 ( 484)
#define ID_YELLOW_CONCRETE                 ( 485)
#define ID_LIME_CONCRETE                   ( 486)
#define ID_GREEN_CONCRETE                  ( 487)
#define ID_CYAN_CONCRETE                   ( 488)
#define ID_LIGHT_BLUE_CONCRETE             ( 489)
#define ID_BLUE_CONCRETE                   ( 490)
#define ID_PURPLE_CONCRETE                 ( 491)
#define ID_MAGENTA_CONCRETE                ( 492)
#define ID_BROWN_CONCRETE                  ( 493)
#define ID_BLACK_CONCRETE_POWDER           ( 494)
#define ID_GRAY_CONCRETE_POWDER            ( 495)
#define ID_LIGHT_GRAY_CONCRETE_POWDER      ( 496)
#define ID_WHITE_CONCRETE_POWDER           ( 497)
#define ID_PINK_CONCRETE_POWDER            ( 498)
#define ID_RED_CONCRETE_POWDER             ( 499)
#define ID_ORANGE_CONCRETE_POWDER          ( 500)
#define ID_YELLOW_CONCRETE_POWDER          ( 501)
#define ID_LIME_CONCRETE_POWDER            ( 502)
#define ID_GREEN_CONCRETE_POWDER           ( 503)
#define ID_CYAN_CONCRETE_POWDER            ( 504)
#define ID_LIGHT_BLUE_CONCRETE_POWDER      ( 505)
#define ID_BLUE_CONCRETE_POWDER            ( 506)
#define ID_PURPLE_CONCRETE_POWDER          ( 507)
#define ID_MAGENTA_CONCRETE_POWDER         ( 508)
#define ID_BROWN_CONCRETE_POWDER           ( 509)
#define ID_BLACK_SHULKER_BOX               ( 510)
#define ID_GRAY_SHULKER_BOX                ( 511)
#define ID_LIGHT_GRAY_SHULKER_BOX          ( 512)
#define ID_WHITE_SHULKER_BOX               ( 513)
#define ID_PINK_SHULKER_BOX                ( 514)
#define ID_RED_SHULKER_BOX                 ( 515)
#define ID_ORANGE_SHULKER_BOX              ( 516)
#define ID_YELLOW_SHULKER_BOX              ( 517)
#define ID_LIME_SHULKER_BOX                ( 518)
#define ID_GREEN_SHULKER_BOX               ( 519)
#define ID_CYAN_SHULKER_BOX                ( 520)
#define ID_LIGHT_BLUE_SHULKER_BOX          ( 521)
#define ID_BLUE_SHULKER_BOX                ( 522)
#define ID_PURPLE_SHULKER_BOX              ( 523)
#define ID_MAGENTA_SHULKER_BOX             ( 524)
#define ID_BROWN_SHULKER_BOX               ( 525)
#define ID_CRUSHED_IRON_ORE                ( 526)
#define ID_IRON_INGOT                      ( 527)
#define ID_IRON_NUGGET                     ( 528)
#define ID_CRUSHED_GOLD_ORE                ( 529)
#define ID_GOLD_INGOT                      ( 530)
#define ID_GOLD_NUGGET                     ( 531)
#define ID_CRUSHED_TIN_ORE                 ( 532)
#define ID_TIN_INGOT                       ( 533)
#define ID_TIN_NUGGET                      ( 534)
#define ID_CRUSHED_COPPER_ORE              ( 535)
#define ID_COPPER_INGOT                    ( 536)
#define ID_COPPER_NUGGET                   ( 537)
#define ID_CRUSHED_LEAD_ORE                ( 538)
#define ID_LEAD_INGOT                      ( 539)
#define ID_LEAD_NUGGET                     ( 540)
#define ID_CRUSHED_ALUMINUM_ORE            ( 541)
#define ID_ALUMINUM_INGOT                  ( 542)
#define ID_ALUMINUM_NUGGET                 ( 543)
#define ID_CRUSHED_NICKEL_ORE              ( 544)
#define ID_NICKEL_INGOT                    ( 545)
#define ID_NICKEL_NUGGET                   ( 546)
#define ID_CRUSHED_SILVER_ORE              ( 547)
#define ID_SILVER_INGOT                    ( 548)
#define ID_SILVER_NUGGET                   ( 549)
#define ID_CRUSHED_TITANIUM_ORE            ( 550)
#define ID_TITANIUM_INGOT                  ( 551)
#define ID_TITANIUM_NUGGET                 ( 552)
#define ID_CRUSHED_MITHRIL_ORE             ( 553)
#define ID_MITHRIL_INGOT                   ( 554)
#define ID_MITHRIL_NUGGET                  ( 555)
#define ID_BRONZE_INGOT                    ( 556)
#define ID_BRONZE_NUGGET                   ( 557)
#define ID_STEEL_INGOT                     ( 558)
#define ID_STEEL_NUGGET                    ( 559)
#define ID_COAL                            ( 560)
#define ID_REDSTONE_DUST                   ( 561)
#define ID_LAPIS_LAZULI                    ( 562)
#define ID_EMERALD                         ( 563)
#define ID_DIAMOND                         ( 564)
#define ID_RUBY                            ( 565)
#define ID_SAPHIRE                         ( 566)
#define ID_NETHER_QUARTZ                   ( 567)
#define ID_NETHER_BRICK                    ( 568)
#define ID_RED_NETHER_BRICK                ( 569)
#define ID_GLOWSTONE_DUST                  ( 570)
#define ID_CHARCOAL                        ( 571)
#define ID_BRICK                           ( 572)
#define ID_CLAY_BALL                       ( 573)
#define ID_WOODEN_SWORD                    ( 574)
#define ID_WOODEN_AXE                      ( 575)
#define ID_WOODEN_SHOVEL                   ( 576)
#define ID_WOODEN_PICKAXE                  ( 577)
#define ID_WOODEN_HOE                      ( 578)
#define ID_STONE_SWORD                     ( 579)
#define ID_STONE_AXE                       ( 580)
#define ID_STONE_SHOVEL                    ( 581)
#define ID_STONE_PICKAXE                   ( 582)
#define ID_STONE_HOE                       ( 583)
#define ID_IRON_SWORD                      ( 584)
#define ID_IRON_AXE                        ( 585)
#define ID_IRON_SHOVEL                     ( 586)
#define ID_IRON_PICKAXE                    ( 587)
#define ID_IRON_HOE                        ( 588)
#define ID_STEEL_SWORD                     ( 589)
#define ID_STEEL_AXE                       ( 590)
#define ID_STEEL_SHOVEL                    ( 591)
#define ID_STEEL_PICKAXE                   ( 592)
#define ID_STEEL_HOE                       ( 593)
#define ID_DIAMOND_SWORD                   ( 594)
#define ID_DIAMOND_AXE                     ( 595)
#define ID_DIAMOND_SHOVEL                  ( 596)
#define ID_DIAMOND_PICKAXE                 ( 597)
#define ID_DIAMOND_HOE                     ( 598)
#define ID_WOODEN_SHEILD                   ( 599)
#define ID_IRON_SHEILD                     ( 600)
#define ID_TITANIUM_SHEILD                 ( 601)
#define ID_BUCKET                          ( 602)
#define ID_ROPE                            ( 603)
#define ID_BOW                             ( 604)
#define ID_FISHING_ROD                     ( 605)
#define ID_SHEARS                          ( 606)
#define ID_FINT_AND_STEEL                  ( 607)
#define ID_BONEMEAL                        ( 608)
#define ID_LEATHER_CAP                     ( 609)
#define ID_LEATHER_VEST                    ( 610)
#define ID_LEATHER_PANTS                   ( 611)
#define ID_LEATHER_STOCKINGS               ( 612)
#define ID_CHAINMAIL_CAP                   ( 613)
#define ID_CHAINMAIL_VEST                  ( 614)
#define ID_CHAINMAIL_PANTS                 ( 615)
#define ID_CHAINMAIL_STOCKINGS             ( 616)
#define ID_MITHRIL_CAP                     ( 617)
#define ID_MITHRIL_VEST                    ( 618)
#define ID_MITHRIL_PANTS                   ( 619)
#define ID_MITHRIL_STOCKINGS               ( 620)
#define ID_IRON_HELMET                     ( 621)
#define ID_IRON_CHESTPLATE                 ( 622)
#define ID_IRON_LEGGINGS                   ( 623)
#define ID_IRON_BOOTS                      ( 624)
#define ID_STEEL_HELMET                    ( 625)
#define ID_STEEL_CHESTPLATE                ( 626)
#define ID_STEEL_LEGGINGS                  ( 627)
#define ID_STEEL_BOOTS                     ( 628)
#define ID_DIAMOND_HELMET                  ( 629)
#define ID_DIAMOND_CHESTPLATE              ( 630)
#define ID_DIAMOND_LEGGINGS                ( 631)
#define ID_DIAMOND_BOOTS                   ( 632)
#define ID_TITANIUM_HELMET                 ( 633)
#define ID_TITANIUM_CHESTPLATE             ( 634)
#define ID_TITANIUM_LEGGINGS               ( 635)
#define ID_TITANIUM_BOOTS                  ( 636)
#define ID_RAW_BEEF                        ( 637)
#define ID_STEAK                           ( 638)
#define ID_RAW_MUTTON                      ( 639)
#define ID_COOKED_MUTTON                   ( 640)
#define ID_RAW_CHICKEN                     ( 641)
#define ID_COOKED_CHICKEN                  ( 642)
#define ID_RAW_PORKCHOP                    ( 643)
#define ID_COOKED_PORKCHOP                 ( 644)
#define ID_RAW_RABBIT                      ( 645)
#define ID_COOKED_RABBIT                   ( 646)
#define ID_RAW_SALMON                      ( 647)
#define ID_COOKED_SALMON                   ( 648)
#define ID_RAW_COD                         ( 649)
#define ID_COOKED_COD                      ( 650)
#define ID_RAW_TUNA                        ( 651)
#define ID_COOKED_TUNA                     ( 652)
#define ID_RAW_BASS                        ( 653)
#define ID_COOKED_BASS                     ( 654)
#define ID_APPLE                           ( 655)
#define ID_BEETROOT_SEEDS                  ( 656)
#define ID_BEETROOT_PLANT                  ( 657)
#define ID_BEETROOT                        ( 658)
#define ID_BERRY_BUSH                      ( 659)
#define ID_BERRIES                         ( 660)
#define ID_BROWN_MUSHROOM                  ( 661)
#define ID_CARROT_PLANT                    ( 662)
#define ID_CARROT                          ( 663)
#define ID_MELLON_STEM                     ( 664)
#define ID_MELLON                          ( 665)
#define ID_MELLON_WEDGE                    ( 666)
#define ID_POTATO_PLANT                    ( 667)
#define ID_POTATO                          ( 668)
#define ID_PUMPKIN_STEM                    ( 669)
#define ID_PUMPKIN                         ( 670)
#define ID_RED_MUSHROOM                    ( 671)
#define ID_SUGAR_CANES                     ( 672)
#define ID_SUGAR                           ( 673)
#define ID_WHEAT_SEEDS                     ( 674)
#define ID_WHEAT_PLANT                     ( 675)
#define ID_WHEAT                           ( 676)
#define ID_BAMBOO                          ( 677)
#define ID_CACTUS                          ( 678)
#define ID_DEAD_BRUSH                      ( 679)
#define ID_DRY_REEDS                       ( 680)
#define ID_FERN                            ( 681)
#define ID_GRASS                           ( 682)
#define ID_KELP                            ( 683)
#define ID_LILY_PAD                        ( 684)
#define ID_SEAGRASS                        ( 685)
#define ID_SWEET_BERRY_BUSH                ( 686)
#define ID_TALL_FERN                       ( 687)
#define ID_TALL_GRASS                      ( 688)
#define ID_TALL_SEAGRASS                   ( 689)
#define ID_VINES                           ( 690)
#define ID_ALLIUM                          ( 691)
#define ID_AZURE_BLUET                     ( 692)
#define ID_BLUE_ORCHID                     ( 693)
#define ID_DANDELION                       ( 694)
#define ID_LILAC                           ( 695)
#define ID_ORANGE_TULIP                    ( 696)
#define ID_OXEYE_DAISY                     ( 697)
#define ID_PEONY                           ( 698)
#define ID_PINK_TULIP                      ( 699)
#define ID_POPPY                           ( 700)
#define ID_RED_TULIP                       ( 701)
#define ID_ROSE_BUSH                       ( 702)
#define ID_SUNFLOWER                       ( 703)
#define ID_WHITE_TULIP                     ( 704)



#endif


