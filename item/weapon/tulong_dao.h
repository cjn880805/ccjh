//tulong_dao.h ������
//�ز� 2002-5-11

EQUIP_BEGIN(CItulong_dao);

virtual void create(int nFlag = 0)		
{
	set_name( "������");	

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(70000);		//set item weight

	set("unit", "��");
	set("long", "�����д����Ѿõ���������������콣���ᣬ�ഫ��һ�Է�Ϊ���Ȿ����������ͼ�պ����˶����ɣ�������˵�����Ѳ��ɿ�������������������������Ȼ������ƥ��");
	set("material", "steel");
	set("weapon/strength", 10);
	set("wield_msg",  "$N��������������Х������$HIR�������𣬱����������������£�Ī�Ҳ��ӡ�$COM��" );
	set("unwield_msg",  "ֻ��$N�����ŵ������������������ܵ�����ʲô�أ������֮�佫����������������" );

	set("apply/damage", 1000);					//set the modifiers of attribute
 
};

EQUIP_END;

//last, register the item into ../server/ItemSetup.cpp



