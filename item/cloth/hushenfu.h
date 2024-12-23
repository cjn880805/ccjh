//hushenfu.h
//Lanwood 2001-03-10
//�������װ���Ͽ��Բ����������ɧ��

EQUIP_BEGIN(CIhushenfu);

virtual void create(int nFlag = 0)
{
	char msg[80], str[20];
	set("wield_position", WIELD_NECK);		//set the position of wield
 	set_weight(500);		//set item weight
   
	int level = nFlag;

	if(! nFlag) level = random(20) + 1;
	
	set("index", level);

	set_name( snprintf(msg, 80, "%s�������", chinese_number(level, str)));	//set item name
	set("long", snprintf(msg, 80, "���������Ļ��������������%s�����¹��", str));
	set("value", 5000 + level * 400);
	
	set("apply/armor", 0l);
	set("apply/protect", level);
	set("wear_msg", "$N����ذ�$n���ھ��ϡ�");
	set("unequip_msg", "$N����ذ�$n�Ӿ���ժ��������");
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp