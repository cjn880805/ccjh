//pinganfu.h
//sound 2001-12-10
//ƽ������װ���Ͽ��Բ����������ɧ��

EQUIP_BEGIN(CIpinganfu);

virtual void create(int nFlag = 0)
{
	char msg[80], str[20];
	set("wield_position", WIELD_NECK);		//set the position of wield
 	set_weight(5000);		//set item weight
   
	int level = nFlag;

	if(! nFlag) level = random(20) + 1;
	
	set("index", level);

	set_name( snprintf(msg, 80, "%s��ƽ����", chinese_number(level, str)));	//set item name
	set("long", "�ڵ����ﱣƽ����ƽ���������Լ��ٱ������˺��ļ��ʡ�");
	set("value", 5000 + level * 400);
	
	set("apply/armor", 0l);
	set("apply/safety", level);
	set("wear_msg", "$N����ذ�$n���ھ��ϡ�");
	set("unequip_msg", "$N����ذ�$n�Ӿ���ժ��������");
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp