//dagou.h
//Sample for room: ̨��򹷸�
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRTaiWan_dagou);

virtual void create()			//Call it when Room Create
{

	set_name( "̨��򹷸�");
	set("monster_chance", 20);

	add_npc("pub_wokou");
	add_npc("taiwan_scavenger");
	add_npc("pub_panjianke");

	add_door("̨��ĵ�", "̨��ĵ�", "̨��򹷸�");
	add_door("Ȫ�������", "Ȫ�������", "̨��򹷸�");

	set("long", "�򹷸�λ��̨���ϲ��������С�������е����������ھ�����Ͽ�壬��ǫ̈̄��һ���ۡ�  " );
};

ROOM_END;
