//xiaoyao_feiling2.h ����֮ñ
//�ز� 2003��3��15

XiaoYao_BEGIN(CRXiaoYao_feiling2);

virtual void create()
{
	set_name( "����֮ñ");
	set("no_autosave",1);
	set("index",2);

	add_item("shicheng");
	add_door("����֮�����", "��ң�ȷ���֮�����", "��ң�ȷ���֮ñ");
	add_door("����֮�Ҽ���", "��ң�ȷ���֮�Ҽ���", "��ң�ȷ���֮ñ");
	add_door("����֮��", "��ң�ȷ���֮��", "��ң�ȷ���֮ñ");

};

XiaoYao_END;
