//chiqian.h

//Sample for room: ̨���Ƕ��
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRTaiWan_chiqian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̨���Ƕ��");

	set("monster_chance", 20);

	add_npc("pub_hongmao");
	add_npc("pub_changhentian");
	
	add_door("̨��ĵ�", "̨��ĵ�", "̨���Ƕ��");

	set("long", "�˵�Ϊ̨�帮פ����̨�忪��δ�ã�����ү�������ո��˳ǣ�Χ����ë�������֮�ã����½����ȱ��    ���⺣�ۣ�����(zhou)�����������" );

};


ROOM_END;
