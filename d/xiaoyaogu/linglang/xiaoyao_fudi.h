//xiaoyao_fudi.h ��ߧ����
//�ز� 2003��3��15

XiaoYao_BEGIN(CRXiaoYao_fudi);

virtual void create()
{
	set_name( "��ߧ����");
	set("no_autosave",1);
	set("long","������Բ��ʯ�ң��������ʯ�ڵ�һ���ˮ����Լ��ͭ���С���������ˮ�����������ʵ�͸�롣��ˮ��������ȥ��ֻ������ˮ����ס�϶�����Ϻˮ�������ζ�����Ŀ���������޾�����");

	add_door("ʯ��1", "��ң����ߧ����ʯ��1", "��ң����ߧ����");
	add_door("ʯ��2", "��ң����ߧ����ʯ��2", "��ң����ߧ����");
	add_door("ʯ��3", "��ң����ߧ����ʯ��3", "��ң����ߧ����");
	add_door("ʯ��4", "��ң����ߧ����ʯ��4", "��ң����ߧ����");
	add_door("��ߧ���ض���", "��ң����ߧ���ض���", "��ң����ߧ����");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

XiaoYao_END;
