//banshan.h

//Sample for room: 大理城半山竹林
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_banshan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城半山竹林");

	set("resident", "步雄部");

	//add npcs into the room
	add_npc("pub_kanzhuren");
	
	add_door("大理城林中山涧", "大理城林中山涧", "大理城半山竹林");
	add_door("大理城步雄部", "大理城步雄部", "大理城半山竹林");

	set("long", "一大片茂密的成年竹林生长在半山腰的缓坡上。竹子对大理地区各民族来说是，既是重要的建筑材料，也是日常生活用品的原材料。山下的村庄里的摆夷人经常上山来采伐竹子。北面山上有溪流下，到这里水流已经颇大，山民经常把砍伐下的竹子丢在溪中，任其顺水飘流，到村子附近的溪水里再捞起来。" );
};


RESIDENT_END;
