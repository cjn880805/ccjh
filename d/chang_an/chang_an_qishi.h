//qishi.h

//Sample for room: 长安入神坐照室
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_qishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "长安入神坐照室");

	add_npc("pub_old");   //2001-07-12 zdn add
	add_npc("xy_fanqiansuei"); 

	add_door("长安聚义厅", "长安聚义厅", "长安入神坐照室");

	set("long", " 只见好大一间房中，除了一张石桌、两只石凳之外，空荡荡的一无所有，石桌上刻着纵横十九道棋路，对放着一盒黑子、一盒白子。这棋室中除了几椅棋子之外不设一物，当是免得对局者分心。墙上贴了一张小帖子(tie)。 " );
/*****************************************************
   set("objects", ([  
      __DIR__"obj/table" : 1,
      __DIR__"obj/seat" : 2,
  ]));
  set("item_desc", ([ 
      "tie":
"
在这里您可以下围棋或五子棋，以下告诉您下棋的步骤：
一、先找好对手，然后分别用 sit black 和 sit white 入座；
二、使用 new 开始一盘新的棋局：new [-5] [-b(numbers)] [-h(numbers)]
    其中 -5 代表下五子棋，不选即为下围棋；
　　-b指定所用棋盘的大小；
    -h指定让子的数目；
　　例如：
　　围棋：new
　　十五乘十五的五子棋：new -5 -b15
　　让九子围棋：new -h9
三、使用 play 轮流走棋：例如 play d4 等等。
四、使用 refresh观看棋盘。
五、使用 undo 悔棋。(目前只提供五子棋的悔棋功能。)
六、使用 leave 站起来开路。
"
  ]));
  set("exits", ([  
      "north" : __DIR__"club3",
  ]));

********************************************/

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
CHANGAN_END;
