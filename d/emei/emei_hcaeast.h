//hcaeast.h

//Sample for room:  峨嵋华藏庵东侧殿
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcaeast);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋华藏庵东侧殿");

	add_npc("emei_wenhui");
	add_npc("emei_he");

	add_door("峨嵋华藏庵正殿", "峨嵋华藏庵正殿", "峨嵋华藏庵东侧殿");

	set("long","这里是金顶华藏庵东侧殿，是接待香客及来宾的地方。殿内摆着几张桌子，桌旁围放数把椅子。墙上悬着几幅字画，墙边一排书架，架上摆满经书。有几位进香客正在品茶养神，欣赏墙上的字画或翻阅架上的经书。还有两个二十来岁的姑娘在向一位师太打听有关出家的事。一个十来岁的小师太正在忙前忙后招待客人。");
 
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
