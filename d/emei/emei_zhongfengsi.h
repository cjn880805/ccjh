//zhongfengsi.h

//Sample for room:  峨嵋中峰寺
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_zhongfengsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋中峰寺");

	add_npc("pub_guest");
	add_npc("emei_youngwoman"); 
	add_npc("emei_puren");          //add by zdn 2001-07-20
				
	add_door("峨嵋神水庵", "峨嵋神水庵", "峨嵋中峰寺");
	add_door("峨嵋清音阁", "峨嵋清音阁", "峨嵋中峰寺");

	set("long","中峰寺在白云峰下，始建于晋代，原为道观。传说观内的道人每年在三月三日都献身给山中一条大蟒，以为可以升仙。后来有个从资州来的明果禅师，杀了那条大蟒，道士们始知上当，感激不已，自愿改信佛教，从此改观为寺。这里往北可到清音阁，东下至神水庵。");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;
