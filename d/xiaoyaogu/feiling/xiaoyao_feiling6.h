//xiaoyao_feiling6.h ����֮�ұ���
//�ز� 2003��3��15

XiaoYao_BEGIN(CRXiaoYao_feiling6);

virtual void create()
{
	set_name( "����֮�ұ���");
	set("no_autosave",1);
	set("index",6);

	add_item("shicheng");
	add_door("����֮�Ҽ���", "��ң�ȷ���֮�Ҽ���", "��ң�ȷ���֮�ұ���");
	add_door("��ң�ȷ���֮��", "��ң�ȷ���֮��", "��ң�ȷ���֮�ұ���");
	add_door("����֮������", "��ң�ȷ���֮������", "��ң�ȷ���֮�ұ���");

};

XiaoYao_END;
