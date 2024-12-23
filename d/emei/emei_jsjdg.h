//jsjdg.h

//Sample for room:  峨嵋九十九道拐1
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_jsjdg);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋九十九道拐1");

	add_npc("pub_boydizi");    // add by zdn 2001-07-14
				
	add_door("峨嵋九十九道拐2", "峨嵋九十九道拐2", "峨嵋九十九道拐1");
	add_door("峨嵋千佛庵", "峨嵋千佛庵", "峨嵋九十九道拐1");

	set("long","这是著名的「九十九道拐」，道路纡曲陡竖，千折百回。据说过去曾有个百余岁的疯僧至此，见一巨蟒挡路，便念咒驱蟒。但人们得知此处有巨蟒出没后，便再也无人敢碰这里的草木，并以「龙居」名之。由此东可至千佛庵，西达九老洞。");

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
