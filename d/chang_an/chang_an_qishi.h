//qishi.h

//Sample for room: ��������������
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_qishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������������");

	add_npc("pub_old");   //2001-07-12 zdn add
	add_npc("xy_fanqiansuei"); 

	add_door("����������", "����������", "��������������");

	set("long", " ֻ���ô�һ�䷿�У�����һ��ʯ������ֻʯ��֮�⣬�յ�����һ�����У�ʯ���Ͽ����ݺ�ʮ�ŵ���·���Է���һ�к��ӡ�һ�а��ӡ��������г��˼�������֮�ⲻ��һ�������öԾ��߷��ġ�ǽ������һ��С����(tie)�� " );
/*****************************************************
   set("objects", ([  
      __DIR__"obj/table" : 1,
      __DIR__"obj/seat" : 2,
  ]));
  set("item_desc", ([ 
      "tie":
"
��������������Χ��������壬���¸���������Ĳ��裺
һ�����Һö��֣�Ȼ��ֱ��� sit black �� sit white ������
����ʹ�� new ��ʼһ���µ���֣�new [-5] [-b(numbers)] [-h(numbers)]
    ���� -5 �����������壬��ѡ��Ϊ��Χ�壻
����-bָ���������̵Ĵ�С��
    -hָ�����ӵ���Ŀ��
�������磺
����Χ�壺new
����ʮ���ʮ��������壺new -5 -b15
�����þ���Χ�壺new -h9
����ʹ�� play �������壺���� play d4 �ȵȡ�
�ġ�ʹ�� refresh�ۿ����̡�
�塢ʹ�� undo ���塣(Ŀǰֻ�ṩ������Ļ��幦�ܡ�)
����ʹ�� leave վ������·��
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
