//qingxi.h

//Sample for room: �������Ϫ��̶
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_qingxi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������Ϫ��̶");

	set("resident", "�̼�ɽ");

	//add npcs into the room
	add_npc("pub_biaotou");
	add_npc("xy_licanghai");
	add_npc("pub_liushengshibingwei");
	
	add_door("����Ǳ̼�ɽ��", "����Ǳ̼�ɽ��", "�������Ϫ��̶");
	add_door("������ּ�С��1", "������ּ�С��1", "�������Ϫ��̶");
	add_door("����Ǵ��ˮ�ٲ�", "����Ǵ��ˮ�ٲ�", "�������Ϫ��̶");

	set("long", "��Ϫ��̶����������ˮ�������ڲ�ɽ��������ʥӦ��֮�������Ͽ���С�ɽȪ�Ҹ�ӿ��������к����Ϫ��أ�׳�����裬��������ˮ��ʯ������̽��ӣ����׳����Ϫ��" );
};


RESIDENT_END;




