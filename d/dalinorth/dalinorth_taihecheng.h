//taihecheng.h

//Sample for room: ̫�ͳ�
//coded by zouwenbin
//data: 2000-11-15

RESIDENT_BEGIN(CRDaLiNorth_taihecheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̫�ͳ�");

	set("resident", "̫��");

	//add npcs into the room
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_wujiang");
	add_npc("pub_lijin");
	add_npc("pub_hongfunv");

	add_door("����Ǳ���", "����Ǳ���", "�����̫�ͳ�");
	add_door("�������گ�»���", "�������گ�»���", "�����̫�ͳ�");

	set("long", "�˳�����������θ���ȫ����İ����ʯ�ݳɣ������࣬�������ﲻ�ϡ�̫�Ͳ����ǣ����˿�Ϊ�������٣������Ϻ;������Ǵ���ǵı��Ż������������������ڴ˼ӹ̳ǳأ���פ������������һЩ���Ĳ���۾ӡ�������һƬƽԭ����ʮ���������ǡ�" );

};

RESIDENT_END;
