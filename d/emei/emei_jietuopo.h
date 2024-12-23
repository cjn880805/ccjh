//jietuopo.h

//Sample for room:  峨嵋解脱坡
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_jietuopo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋解脱坡");
	
	add_npc("emei_girldizi");     //add by zdn 200107-20


	CBox * box = Add_Box();
	box->add_object("coin", 80);	//put 100 coind into box
	box->set_name( "漆柜");		//set box's name

				
	add_door("峨嵋密林2", "峨嵋密林2", "峨嵋解脱坡");
	add_door("峨嵋观音堂", "峨嵋观音堂", "峨嵋解脱坡");

	set("long","这里是峨嵋胜地解脱坡。坡下一座小桥，叫解脱桥。行人至此，坐桥上听泉声甚美。当此良辰美景，心无芥蒂，心即解脱。坡上一座庵堂，东下一片密林。桥下山溪向东流淌到报国寺的西面。");

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
