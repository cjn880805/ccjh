//kedian.h

//Sample for room: ������ջ
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRXiangYang_kedian);

virtual void create()			//Call it when Room Create
{
	set_name( "������ջ");

	add_npc("pub_xiaoer2");

	add_door("��������", "��������", "������ջ");

	set("long", "����һ�ҶԽ�����ʿ��˵���������Ŀ�ջ�����ǵ�������һ�㶼ס�����һ�Ǳ��ˣ��������������ϵ�������顣�������������˵���ʮ�Σ��������������Ǿ����������Ǵ���������˳��ݷ�һ�¹���������֮ʿ��" );
	set("sleep_room",1);
	
	set("no_fight", 1);
	set("valid_startroom", 1);

};


ROOM_END;
