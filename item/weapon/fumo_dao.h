//fumo_dao.h

//Sample for ITEM: ��ħ��
//coded by Fisho
//data: 2000-11-24

EQUIP_BEGIN(CIfumo_dao);

virtual void create(int nFlag = 0)	
{
	set_name( "��ħ��");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(10000);		//set item weight
	
	set("unit", "��");
	set("long", "����һ������ѩ���ķ�ħ�������м�������Ѫ��������������ƥ��ӳ���������˵�������ǰ�ɴ�Ħ����Я����ԭ��һ·��֮������ħ�����Ƿ�����Ͻ�ħ������");
	set("value", 1000000);
	set("material", "steel");
	set("no_drop", "�������������뿪�㡣");
	set("no_get", "�������������뿪�Ƕ���");
	set("wield_msg",  "ֻ�������һ������ħ�����ʷɳ�������Ծ��$N���С�˲ʱ��ʼ���Ʊ�ɫ������������������һƬ�ޱ�ɱ�⡣" );
	set("unwield_msg",  "��ħ����$N���з����ڰ����һת����ৡ���Ծ�뵶�ʡ�" );
	set("apply/damage", 1000);					//set the modifiers of attribute
	
};

EQUIP_END;
