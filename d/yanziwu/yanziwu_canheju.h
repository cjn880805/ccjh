//canheju.h

//Sample for room: ������κϾ�
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_canheju);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������κϾ�");

	add_door("����������", "����������", "������κϾ�");
	add_door("��������ˬի", "��������ˬի", "������κϾ�");
	add_door("������׺��¥", "������׺��¥", "������κϾ�");
	add_door("�����뺲ī����", "�����뺲ī����", "������κϾ�");

    set("long", "����Ľ���������������ճ����֮�أ����õû����в������ţ�ƽʵ��͸�Ÿ߹��ľ��������̫ʦ�Σ��Լ�ǽ�ϵ��ֻ���͸��һ�ɷǷ�֮����" );
    
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
//last, register the room into ../server/RoomSetup.cpp