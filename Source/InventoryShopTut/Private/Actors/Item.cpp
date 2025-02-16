// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryShopTut/Public/Actors/Item.h"
#include "InventoryShopTut/InventoryShopTutCharacter.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = ItemMesh;

	bReplicates = true;
	
	ItemData.ItemClass = StaticClass();

	bIsEquipable = false;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItem::Interact(class AInventoryShopTutCharacter* Character)
{
	if (HasAuthority() && Character)
	{
		Character->AddInventoryItem(ItemData);
		Destroy();
	}
}

void AItem::Use(AInventoryShopTutCharacter* Character, bool IsInShop)
{
	if (IsInShop && Character)
	{
		UE_LOG(LogTemp, Warning, TEXT("ADDING TO INVENTORY"));
		Character->AddInventoryItem(ItemData);
	}
}
