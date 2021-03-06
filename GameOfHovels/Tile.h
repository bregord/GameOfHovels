//
//  Tile.h
//  Bastion
//
//  Created by Kayhan Feroze Qaiser on 10/02/2015.
//
//

#import "BasicSprite.h"
#import "Village.h"
#import "Structure.h"
#import "GamePlayer.h"
#import "Unit.h"

@class Unit;

@interface Tile : BasicSprite {
    enum TileNeighbours {TopRight = 0, Right, BottomRight, BottomLeft, Left, TopLeft};

}

@property (nonatomic, readonly) SPImage* baseImage;
@property (nonatomic) Unit* unit;
@property (nonatomic) Village* village;
@property (nonatomic) enum PlayerColor pColor;
@property (nonatomic) BOOL visitedBySearch;

- (id)initWithPosition: (SPPoint*)position structure: (enum StructureType)sType;
- (void)setNeighbour:(enum TileNeighbours)tileNeighbour tile: (Tile*)tile;
- (Tile*)getNeighbour:(enum TileNeighbours)tileNeighbour;
- (NSMutableArray*)getNeighbours;
- (NSMutableArray*)getNeighboursOfSameRegion;
- (NSMutableArray*)getNeighboursOfSameColor;
- (void)makeNeutral;

- (void)setPColor:(enum PlayerColor)pColor;


- (BOOL)neighboursContainTile:(Tile*) tile;
- (enum StructureType)getStructureType;
- (BOOL)isTraversableForUnitType: (int)unitType;
- (void)addVillage:(enum VillageType) vType;
- (void)removeVillage;
- (void)upgradeVillageTo:(enum VillageType) vType;
- (void)mergeVillageBySwallowing:(Village*)v;
- (BOOL)hasVillage;
- (BOOL)isVillage;


- (void)addUnitWithType:(enum UnitType)uType;
- (void)addUnit:(Unit*)unit;
- (void)removeUnit;
- (BOOL)hasUnit;
- (Unit*)getUnit;
- (void)upgradeUnit:(enum UnitType)uType;
- (enum UnitType)getUnitType;
- (void)attackWithCannon;

- (void)selectTile;
- (void)deselectTile;
- (BOOL)canBeSelected;
- (BOOL)canHaveTree;
- (BOOL)canHaveMeadow;
- (BOOL)canHaveRoad;

- (BOOL)canHaveUnit;
- (BOOL)canHaveTower;
- (BOOL)isNeutral;
- (BOOL)hasRoad;
- (BOOL)hasTombstone;
- (BOOL)hasTower;

- (Structure*)getStructure;
- (NSMutableArray*)getStructureTypes;
- (void)addStructure:(enum StructureType)sType;
- (void)removeStructure;
- (void)removeAllStructures;

- (void)endTurnUpdates;

@end