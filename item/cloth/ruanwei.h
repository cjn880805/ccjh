//ruanwei.h ��⬼�

EQUIP_BEGIN(CIruanwei);

virtual void create(int nFlag = 0)	
{
	set_name( "��⬼�", "ruanwei jia");
    set_weight(1000);

	set("wield_position", WIELD_ARMOR);	

	set("unit", "��");
    set("long", "һ����ƮƮ�ġ��������񵹴̵Ļ��ס�");
	set("material", "copper");
	set("value",2000);
	set("no_drop", "�������������뿪�㡣");
	set("no_get", "�������������뿪�Ƕ���");
	set("apply/armor", 75);
	set("apply/dodge", -5);
};

EQUIP_END;
