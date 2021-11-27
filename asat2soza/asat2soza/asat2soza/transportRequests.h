#pragma once

#ifndef H_TRANSPORT_REQUESTS
#define H_TRANSPORT_REQUESTS

#include <ctime>
#include <string>
#include <vector>

/*! Заявка на автотранспорт
 *
 */
class TransportRequestUnit {
public:
    struct tm      time_4_get_vehicle_; //! Дата и время подачи ТС
    unsigned int   passengers_numb_;    //! Количество пассажиров
    float          cargo_volume_; //! Объем груза: undefined => 0.0
    std::string    department_; //! Наименование структурного подразделения
    std::string    route_;  //! Маршрут
    std::string    adress_4_get_vehicle_;   //! Адрес подачи ТС
    std::string    category_vehicle_str_;   //! Категория ТС(текст)
    TransportRequestUnit() {
        struct tm time_def = tm();
        this->time_4_get_vehicle_ = time_def;
        this->passengers_numb_ = 0;
        this->cargo_volume_ = 0.0;
        this->department_ = "";
        this->route_ = "";
        this->adress_4_get_vehicle_ = "";
        this->category_vehicle_str_ = "";
    }

    TransportRequestUnit(const TransportRequestUnit& _Src_Request) {
        struct tm time_def = tm();
        //this->time_4_get_vehicle_ = _Src_Request.time_4_get_vehicle_; //! Дата и время подачи ТС
        this->time_4_get_vehicle_.tm_year = _Src_Request.time_4_get_vehicle_.tm_year;
        this->time_4_get_vehicle_.tm_mon = _Src_Request.time_4_get_vehicle_.tm_mon;
        this->time_4_get_vehicle_.tm_mday = _Src_Request.time_4_get_vehicle_.tm_mday;
        this->time_4_get_vehicle_.tm_hour = _Src_Request.time_4_get_vehicle_.tm_hour;
        this->time_4_get_vehicle_.tm_min = _Src_Request.time_4_get_vehicle_.tm_min;
        this->time_4_get_vehicle_.tm_sec = _Src_Request.time_4_get_vehicle_.tm_sec;

        this->time_4_get_vehicle_.tm_isdst = _Src_Request.time_4_get_vehicle_.tm_isdst;
        this->time_4_get_vehicle_.tm_wday = _Src_Request.time_4_get_vehicle_.tm_wday;
        this->time_4_get_vehicle_.tm_yday = _Src_Request.time_4_get_vehicle_.tm_yday;


        this->passengers_numb_ = _Src_Request.passengers_numb_;    //! Количество пассажиров
        this->cargo_volume_ = _Src_Request.cargo_volume_; //! Объем груза: undefined => 0.0
        this->department_ = _Src_Request.department_; //! Наименование структурного подразделения
        this->route_ = _Src_Request.route_;  //! Маршрут
        this->adress_4_get_vehicle_ = _Src_Request.adress_4_get_vehicle_;   //! Адрес подачи ТС
        this->category_vehicle_str_ = _Src_Request.category_vehicle_str_;   //! Категория ТС(текст)
    }

    //TransportRequestUnit(const time_t &      _time_4_get_vehicle,
    //                     const unsigned int  _passengers_numb = 0,
    //                     const float         _cargo_volume_ = 0,
    //                     const std::string & _department = "",
    //                     const std::string & _route = "",
    //                     const std::string & _adress_4_get_vehicle = "",
    //                     const std::string& _category_vehicle_str = ""
    //                    ) {
    //    
    //}

    TransportRequestUnit& operator=(const TransportRequestUnit& _Src_Request) 
    {
        if (this == &_Src_Request)
            return *this;

        struct tm time_def = tm();
        //this->time_4_get_vehicle_ = _Src_Request.time_4_get_vehicle_; //! Дата и время подачи ТС
        this->time_4_get_vehicle_.tm_year = _Src_Request.time_4_get_vehicle_.tm_year;
        this->time_4_get_vehicle_.tm_mon = _Src_Request.time_4_get_vehicle_.tm_mon;
        this->time_4_get_vehicle_.tm_mday = _Src_Request.time_4_get_vehicle_.tm_mday;
        this->time_4_get_vehicle_.tm_hour = _Src_Request.time_4_get_vehicle_.tm_hour;
        this->time_4_get_vehicle_.tm_min = _Src_Request.time_4_get_vehicle_.tm_min;
        this->time_4_get_vehicle_.tm_sec = _Src_Request.time_4_get_vehicle_.tm_sec;

        this->time_4_get_vehicle_.tm_isdst = _Src_Request.time_4_get_vehicle_.tm_isdst;
        this->time_4_get_vehicle_.tm_wday = _Src_Request.time_4_get_vehicle_.tm_wday;
        this->time_4_get_vehicle_.tm_yday = _Src_Request.time_4_get_vehicle_.tm_yday;


        this->passengers_numb_ = _Src_Request.passengers_numb_;    //! Количество пассажиров
        this->cargo_volume_ = _Src_Request.cargo_volume_; //! Объем груза: undefined => 0.0
        this->department_ = _Src_Request.department_; //! Наименование структурного подразделения
        this->route_ = _Src_Request.route_;  //! Маршрут
        this->adress_4_get_vehicle_ = _Src_Request.adress_4_get_vehicle_;   //! Адрес подачи ТС
        this->category_vehicle_str_ = _Src_Request.category_vehicle_str_;   //! Категория ТС(текст)
        return *this;
    }
    bool operator<(const TransportRequestUnit& _Src_Request)
    {
        if (this == &_Src_Request)
            return false;

        bool is_less_time_4_get_vehicle_ = false;
        bool is_less_adress_4_get_vehicle_ = false;
        bool is_less_category_vehicle_str_ = false;
        bool is_less_passengers_numb_ = false;
        bool is_less_route_ = false;

        is_less_time_4_get_vehicle_ = 
            this->time_4_get_vehicle_.tm_year < _Src_Request.time_4_get_vehicle_.tm_year ||
            this->time_4_get_vehicle_.tm_mon < _Src_Request.time_4_get_vehicle_.tm_mon ||
            this->time_4_get_vehicle_.tm_mday < _Src_Request.time_4_get_vehicle_.tm_mday ||
            this->time_4_get_vehicle_.tm_hour < _Src_Request.time_4_get_vehicle_.tm_hour ||
            this->time_4_get_vehicle_.tm_min < _Src_Request.time_4_get_vehicle_.tm_min ||
            this->time_4_get_vehicle_.tm_sec < _Src_Request.time_4_get_vehicle_.tm_sec ;

        is_less_adress_4_get_vehicle_ = this->adress_4_get_vehicle_ < _Src_Request.adress_4_get_vehicle_;
        is_less_route_ = this->route_ < _Src_Request.route_;
        is_less_category_vehicle_str_ = this->category_vehicle_str_ < _Src_Request.category_vehicle_str_;
        is_less_passengers_numb_ = this->passengers_numb_ < _Src_Request.passengers_numb_;

        return is_less_time_4_get_vehicle_ || is_less_adress_4_get_vehicle_ || is_less_route_ || is_less_category_vehicle_str_ || is_less_passengers_numb_;
    }

    bool operator==(const TransportRequestUnit& _Src_Request)
    {
        if (this == &_Src_Request)
            return true;

        bool is_equal_time_4_get_vehicle_ = false;
        bool is_equal_adress_4_get_vehicle_ = false;
        bool is_equal_category_vehicle_str_ = false;
        bool is_equal_passengers_numb_ = false;
        bool is_equal_route_ = false;

        is_equal_time_4_get_vehicle_ =
            this->time_4_get_vehicle_.tm_year < _Src_Request.time_4_get_vehicle_.tm_year ||
            this->time_4_get_vehicle_.tm_mon < _Src_Request.time_4_get_vehicle_.tm_mon ||
            this->time_4_get_vehicle_.tm_mday < _Src_Request.time_4_get_vehicle_.tm_mday ||
            this->time_4_get_vehicle_.tm_hour < _Src_Request.time_4_get_vehicle_.tm_hour ||
            this->time_4_get_vehicle_.tm_min < _Src_Request.time_4_get_vehicle_.tm_min ||
            this->time_4_get_vehicle_.tm_sec < _Src_Request.time_4_get_vehicle_.tm_sec;

        is_equal_adress_4_get_vehicle_ = this->adress_4_get_vehicle_ < _Src_Request.adress_4_get_vehicle_;
        is_equal_route_ = this->route_ < _Src_Request.route_;
        is_equal_category_vehicle_str_ = this->category_vehicle_str_ < _Src_Request.category_vehicle_str_;
        is_equal_passengers_numb_ = this->passengers_numb_ < _Src_Request.passengers_numb_;

        return is_equal_time_4_get_vehicle_ && is_equal_adress_4_get_vehicle_ && is_equal_route_ && is_equal_category_vehicle_str_ && is_equal_passengers_numb_;
    }


};

/*! Заявка на автотранспорт (выгрузка АСАТ)
 *
 */
class TransportRequestUnitFull : public TransportRequestUnit {
public:
    std::string    request_numb_;   //! Номер заявки
    std::string    request_id_intro_;   //! Внутренний ИД заявки исполнителя
    std::string    status_description_; //! Описание статуса
    struct tm      time_return_vehicle_;    //! Время возвращения ТС
    std::string    priority_str_;  //! Приоритет (string)
    unsigned short priority_code_;  //! Приоритет (uint)
    std::string    request_type_str_;   //! Тип заявки
    std::string    employee_full_name_; //! ФИО сотрудника
    std::string    purpose_trip;    //! Цель поездки
             int   category_vehicle_code_;   //! Категория ТС(int)
    std::string    gosnomer_vehicle_;   //! госномер ТС
    std::string    setevoynomer_vehicle_;    //! сетевой номер ТС
    bool           is_intercity_;   //! междугороднаяя перевозка (признак)
             int   reject_reason_;  //! причина отказа
    std::string    reject_reason_str_;  //! причина отказа (текст) 
    std::string    answer_;  //! все поля с меткой Ответ: (разделены символом ';')
             int   affiliation_type_vehicle_;   //! Тип транспортного средства по принадлежн
    std::string    signature_pixmap_;   //! пиктограмма подписи
    std::string    signature_fullname_; //! ФИО подписавшего
    struct tm      signature_time_; //! дата и время подписи
    std::string    waybill_number_; //! Номер путевого листа
    struct tm      OTZ_time_beg_;   //! ОТЗ. дата и Время начала
    struct tm      OTZ_time_end_;   //! ОТЗ. дата и Время конца
    float          OTZ_timework_;   //! ОТЗ. Время работы на заказчика

    std::string    OTZ;  //! все поля с меткой Ответ: (разделены символом ';')
    bool           is_vehicle_not_RZD_; //! ТС не РЖД (признак)
    std::string    MTA_numb_executor_;  //! Номер МТА от Исполнителя
             int   area_department_;    //! Участок структурного подразделения
    std::string    violations_str_; //! Наименование нарушения при выполнении
             int   BE_; //! БЕ
    struct tm      request_time_;   //! Дата заявки
             int   request_ID_; //! ID заявки на перевозку
             int   request_status_; //! Статус заявки на перевозку
    struct tm      request_status_time_;   //! Дата и время заявки
    struct tm      work_time_;   //! Время работы на заказчика
    std::string    request_type_;   //! Тип заявки на перевозку
    std::string    voucher_status_; //! Статус проверки талона
    std::string    voucher_check_errors_;//! Ошибки при сверке талона
             int   region_code_;    //! Регион
    std::string    region_str_; //! Название региона
    std::string    motor_depot_str_;    //! Наименование автобазы/автоколонны
    bool           is_request_cancel_by_deadline_;  //! Заявка отменена с нарушением сроков

    TransportRequestUnitFull() : TransportRequestUnit() {
        struct tm time_def = tm();
        this->request_numb_ = "";
        this->request_id_intro_ = "";
        this->status_description_ = "";
        this->time_return_vehicle_ = time_def;
        this->priority_str_ = "";
        this->priority_code_ = 0;
        this->request_type_str_ = "";
        this->employee_full_name_ = "";
        this->purpose_trip = "";
        this->category_vehicle_code_ = 0;
        this->gosnomer_vehicle_ = "";
        this->setevoynomer_vehicle_ = "";
        this->is_intercity_ = "";
        this->reject_reason_ = 0;
        this->reject_reason_str_ = "";
        this->answer_ = "";
        this->affiliation_type_vehicle_ = 0;
        this->signature_pixmap_ = "";
        this->signature_fullname_ = "";
        this->signature_time_ = time_def;
        this->waybill_number_ = "";
        this->OTZ_time_beg_ = time_def;
        this->OTZ_time_end_ = time_def;
        this->OTZ_timework_ = 0.0;

        this->OTZ = "";
        this->is_vehicle_not_RZD_ = false;
        this->MTA_numb_executor_ = "";
        this->area_department_ = 0;
        this->violations_str_ = "";
        this->BE_ = 0;
        this->request_time_ = time_def;
        this->request_ID_ = 0;
        this->request_status_ = 0;
        this->request_status_time_ = time_def;
        this->work_time_ = time_def;
        this->request_type_ = "";
        this->voucher_status_ = "";
        this->voucher_check_errors_ = "";
        this->region_code_ = 0;
        this->region_str_ = "";
        this->motor_depot_str_ = "";
        this->is_request_cancel_by_deadline_ = false;
    }

    TransportRequestUnitFull(const TransportRequestUnitFull & _Src_Request) : TransportRequestUnit(_Src_Request){
        struct tm time_def = tm();
        //this->time_4_get_vehicle_ = _Src_Request.time_4_get_vehicle_; //! Дата и время подачи ТС
        this->time_4_get_vehicle_.tm_year = _Src_Request.time_4_get_vehicle_.tm_year;
        this->time_4_get_vehicle_.tm_mon = _Src_Request.time_4_get_vehicle_.tm_mon;
        this->time_4_get_vehicle_.tm_mday = _Src_Request.time_4_get_vehicle_.tm_mday;
        this->time_4_get_vehicle_.tm_hour = _Src_Request.time_4_get_vehicle_.tm_hour;
        this->time_4_get_vehicle_.tm_min = _Src_Request.time_4_get_vehicle_.tm_min;
        this->time_4_get_vehicle_.tm_sec = _Src_Request.time_4_get_vehicle_.tm_sec;

        this->time_4_get_vehicle_.tm_isdst = _Src_Request.time_4_get_vehicle_.tm_isdst;
        this->time_4_get_vehicle_.tm_wday = _Src_Request.time_4_get_vehicle_.tm_wday;
        this->time_4_get_vehicle_.tm_yday = _Src_Request.time_4_get_vehicle_.tm_yday;


        this->passengers_numb_ = _Src_Request.passengers_numb_;    //! Количество пассажиров
        this->cargo_volume_ = _Src_Request.cargo_volume_; //! Объем груза: undefined => 0.0
        this->department_ = _Src_Request.department_; //! Наименование структурного подразделения
        this->route_ = _Src_Request.route_;  //! Маршрут
        this->adress_4_get_vehicle_ = _Src_Request.adress_4_get_vehicle_;   //! Адрес подачи ТС
        this->category_vehicle_str_ = _Src_Request.category_vehicle_str_;   //! Категория ТС(текст)

        this->request_numb_ = _Src_Request.request_numb_;   //! Номер заявки
        this->request_id_intro_ = _Src_Request.request_id_intro_;   //! Внутренний ИД заявки исполнителя
        this->status_description_ = _Src_Request.status_description_; //! Описание статуса
        this->time_return_vehicle_ = _Src_Request.time_return_vehicle_;    //! Время возвращения ТС
        this->priority_str_ = _Src_Request.priority_str_;  //! Приоритет (string)
        this->priority_code_ = _Src_Request.priority_code_;  //! Приоритет (uint)
        this->request_type_str_ = _Src_Request.request_type_str_;   //! Тип заявки
        this->employee_full_name_ = _Src_Request.employee_full_name_; //! ФИО сотрудника
        this->purpose_trip = _Src_Request.purpose_trip;    //! Цель поездки
        this->category_vehicle_code_ = _Src_Request.category_vehicle_code_;   //! Категория ТС(int)
        this->gosnomer_vehicle_ = _Src_Request.gosnomer_vehicle_;   //! госномер ТС
        this->setevoynomer_vehicle_ = _Src_Request.setevoynomer_vehicle_;    //! сетевой номер ТС
        this->is_intercity_ = _Src_Request.is_intercity_;   //! междугороднаяя перевозка (признак)
        this->reject_reason_ = _Src_Request.reject_reason_;  //! причина отказа
        this->reject_reason_str_ = _Src_Request.reject_reason_str_;  //! причина отказа (текст) 
        this->answer_ = _Src_Request.answer_;  //! все поля с меткой Ответ: (разделены символом ';')
        this->affiliation_type_vehicle_ = _Src_Request.affiliation_type_vehicle_;   //! Тип транспортного средства по принадлежн
        this->signature_pixmap_ = _Src_Request.signature_pixmap_;   //! пиктограмма подписи
        this->signature_fullname_ = _Src_Request.signature_fullname_; //! ФИО подписавшего
        this->signature_time_ = _Src_Request.signature_time_; //! дата и время подписи
        this->waybill_number_ = _Src_Request.waybill_number_; //! Номер путевого листа
        this->OTZ_time_beg_ = _Src_Request.OTZ_time_beg_;   //! ОТЗ. дата и Время начала
        this->OTZ_time_end_ = _Src_Request.OTZ_time_end_;   //! ОТЗ. дата и Время конца
        this->OTZ_timework_ = _Src_Request.OTZ_timework_;   //! ОТЗ. Время работы на заказчика

        this->OTZ = _Src_Request.OTZ;  //! все поля с меткой Ответ: (разделены символом ';')
        this->is_vehicle_not_RZD_ = _Src_Request.is_vehicle_not_RZD_; //! ТС не РЖД (признак)
        this->MTA_numb_executor_ = _Src_Request.MTA_numb_executor_;  //! Номер МТА от Исполнителя
        this->area_department_ = _Src_Request.area_department_;    //! Участок структурного подразделения
        this->violations_str_ = _Src_Request.violations_str_; //! Наименование нарушения при выполнении
        this->BE_ = _Src_Request.BE_; //! БЕ
        this->request_time_ = _Src_Request.request_time_;   //! Дата заявки
        this->request_ID_ = _Src_Request.request_ID_; //! ID заявки на перевозку
        this->request_status_ = _Src_Request.request_status_; //! Статус заявки на перевозку
        this->request_status_time_ = _Src_Request.request_status_time_;   //! Дата и время заявки
        this->work_time_ = _Src_Request.work_time_;   //! Время работы на заказчика
        this->request_type_ = _Src_Request.request_type_;   //! Тип заявки на перевозку
        this->voucher_status_ = _Src_Request.voucher_status_; //! Статус проверки талона
        this->voucher_check_errors_ = _Src_Request.voucher_check_errors_;//! Ошибки при сверке талона
        this->region_code_ = _Src_Request.region_code_;    //! Регион
        this->region_str_ = _Src_Request.region_str_; //! Название региона
        this->motor_depot_str_ = _Src_Request.motor_depot_str_;    //! Наименование автобазы/автоколонны
        this->is_request_cancel_by_deadline_ = _Src_Request.is_request_cancel_by_deadline_;  //! Заявка отменена с нарушением сроков
    }

    TransportRequestUnitFull& operator=(const TransportRequestUnitFull & _Src_Request) 
    {
        if (this == &_Src_Request)
            return *this;

        struct tm time_def = tm();
        //this->time_4_get_vehicle_ = _Src_Request.time_4_get_vehicle_; //! Дата и время подачи ТС
        this->time_4_get_vehicle_.tm_year = _Src_Request.time_4_get_vehicle_.tm_year;
        this->time_4_get_vehicle_.tm_mon = _Src_Request.time_4_get_vehicle_.tm_mon;
        this->time_4_get_vehicle_.tm_mday = _Src_Request.time_4_get_vehicle_.tm_mday;
        this->time_4_get_vehicle_.tm_hour = _Src_Request.time_4_get_vehicle_.tm_hour;
        this->time_4_get_vehicle_.tm_min = _Src_Request.time_4_get_vehicle_.tm_min;
        this->time_4_get_vehicle_.tm_sec = _Src_Request.time_4_get_vehicle_.tm_sec;
        
        this->time_4_get_vehicle_.tm_isdst = _Src_Request.time_4_get_vehicle_.tm_isdst;
        this->time_4_get_vehicle_.tm_wday = _Src_Request.time_4_get_vehicle_.tm_wday;
        this->time_4_get_vehicle_.tm_yday = _Src_Request.time_4_get_vehicle_.tm_yday;

        this->passengers_numb_ = _Src_Request.passengers_numb_;    //! Количество пассажиров
        this->cargo_volume_ = _Src_Request.cargo_volume_; //! Объем груза: undefined => 0.0
        this->department_ = _Src_Request.department_; //! Наименование структурного подразделения
        this->route_ = _Src_Request.route_;  //! Маршрут
        this->adress_4_get_vehicle_ = _Src_Request.adress_4_get_vehicle_;   //! Адрес подачи ТС
        this->category_vehicle_str_ = _Src_Request.category_vehicle_str_;   //! Категория ТС(текст)

        this->request_numb_ = _Src_Request.request_numb_;   //! Номер заявки
        this->request_id_intro_ = _Src_Request.request_id_intro_;   //! Внутренний ИД заявки исполнителя
        this->status_description_ = _Src_Request.status_description_; //! Описание статуса
        this->time_return_vehicle_ = _Src_Request.time_return_vehicle_;    //! Время возвращения ТС
        this->priority_str_ = _Src_Request.priority_str_;  //! Приоритет (string)
        this->priority_code_ = _Src_Request.priority_code_;  //! Приоритет (uint)
        this->request_type_str_ = _Src_Request.request_type_str_;   //! Тип заявки
        this->employee_full_name_ = _Src_Request.employee_full_name_; //! ФИО сотрудника
        this->purpose_trip = _Src_Request.purpose_trip;    //! Цель поездки
        this->category_vehicle_code_ = _Src_Request.category_vehicle_code_;   //! Категория ТС(int)
        this->gosnomer_vehicle_ = _Src_Request.gosnomer_vehicle_;   //! госномер ТС
        this->setevoynomer_vehicle_ = _Src_Request.setevoynomer_vehicle_;    //! сетевой номер ТС
        this->is_intercity_ = _Src_Request.is_intercity_;   //! междугороднаяя перевозка (признак)
        this->reject_reason_ = _Src_Request.reject_reason_;  //! причина отказа
        this->reject_reason_str_ = _Src_Request.reject_reason_str_;  //! причина отказа (текст) 
        this->answer_ = _Src_Request.answer_;  //! все поля с меткой Ответ: (разделены символом ';')
        this->affiliation_type_vehicle_ = _Src_Request.affiliation_type_vehicle_;   //! Тип транспортного средства по принадлежн
        this->signature_pixmap_ = _Src_Request.signature_pixmap_;   //! пиктограмма подписи
        this->signature_fullname_ = _Src_Request.signature_fullname_; //! ФИО подписавшего
        this->signature_time_ = _Src_Request.signature_time_; //! дата и время подписи
        this->waybill_number_ = _Src_Request.waybill_number_; //! Номер путевого листа
        this->OTZ_time_beg_ = _Src_Request.OTZ_time_beg_;   //! ОТЗ. дата и Время начала
        this->OTZ_time_end_ = _Src_Request.OTZ_time_end_;   //! ОТЗ. дата и Время конца
        this->OTZ_timework_ = _Src_Request.OTZ_timework_;   //! ОТЗ. Время работы на заказчика

        this->OTZ = _Src_Request.OTZ;  //! все поля с меткой Ответ: (разделены символом ';')
        this->is_vehicle_not_RZD_ = _Src_Request.is_vehicle_not_RZD_; //! ТС не РЖД (признак)
        this->MTA_numb_executor_ = _Src_Request.MTA_numb_executor_;  //! Номер МТА от Исполнителя
        this->area_department_ = _Src_Request.area_department_;    //! Участок структурного подразделения
        this->violations_str_ = _Src_Request.violations_str_; //! Наименование нарушения при выполнении
        this->BE_ = _Src_Request.BE_; //! БЕ
        this->request_time_ = _Src_Request.request_time_;   //! Дата заявки
        this->request_ID_ = _Src_Request.request_ID_; //! ID заявки на перевозку
        this->request_status_ = _Src_Request.request_status_; //! Статус заявки на перевозку
        this->request_status_time_ = _Src_Request.request_status_time_;   //! Дата и время заявки
        this->work_time_ = _Src_Request.work_time_;   //! Время работы на заказчика
        this->request_type_ = _Src_Request.request_type_;   //! Тип заявки на перевозку
        this->voucher_status_ = _Src_Request.voucher_status_; //! Статус проверки талона
        this->voucher_check_errors_ = _Src_Request.voucher_check_errors_;//! Ошибки при сверке талона
        this->region_code_ = _Src_Request.region_code_;    //! Регион
        this->region_str_ = _Src_Request.region_str_; //! Название региона
        this->motor_depot_str_ = _Src_Request.motor_depot_str_;    //! Наименование автобазы/автоколонны
        this->is_request_cancel_by_deadline_ = _Src_Request.is_request_cancel_by_deadline_;  //! Заявка отменена с нарушением сроков
        return *this;
    }

    bool operator<(const TransportRequestUnitFull& _Src_Request)
    {
        if (this == &_Src_Request)
            return false;

        bool is_less_time_4_get_vehicle_ = false;
        bool is_less_adress_4_get_vehicle_ = false;
        bool is_less_category_vehicle_str_ = false;
        bool is_less_passengers_numb_ = false;
        bool is_less_route_ = false;

        is_less_time_4_get_vehicle_ =
            this->time_4_get_vehicle_.tm_year < _Src_Request.time_4_get_vehicle_.tm_year ||
            this->time_4_get_vehicle_.tm_mon < _Src_Request.time_4_get_vehicle_.tm_mon ||
            this->time_4_get_vehicle_.tm_mday < _Src_Request.time_4_get_vehicle_.tm_mday ||
            this->time_4_get_vehicle_.tm_hour < _Src_Request.time_4_get_vehicle_.tm_hour ||
            this->time_4_get_vehicle_.tm_min < _Src_Request.time_4_get_vehicle_.tm_min ||
            this->time_4_get_vehicle_.tm_sec < _Src_Request.time_4_get_vehicle_.tm_sec;

        is_less_adress_4_get_vehicle_ = this->adress_4_get_vehicle_ < _Src_Request.adress_4_get_vehicle_;
        is_less_route_ = this->route_ < _Src_Request.route_;
        is_less_category_vehicle_str_ = this->category_vehicle_str_ < _Src_Request.category_vehicle_str_;
        is_less_passengers_numb_ = this->passengers_numb_ < _Src_Request.passengers_numb_;

        return is_less_time_4_get_vehicle_ || is_less_adress_4_get_vehicle_ || is_less_route_ || is_less_category_vehicle_str_ || is_less_passengers_numb_;
    }
    bool operator==(const TransportRequestUnitFull& _Src_Request)
    {
        if (this == &_Src_Request)
            return true;

        bool is_equal_time_4_get_vehicle_ = false;
        bool is_equal_adress_4_get_vehicle_ = false;
        bool is_equal_category_vehicle_str_ = false;
        bool is_equal_passengers_numb_ = false;
        bool is_equal_route_ = false;

        is_equal_time_4_get_vehicle_ =
            this->time_4_get_vehicle_.tm_year < _Src_Request.time_4_get_vehicle_.tm_year ||
            this->time_4_get_vehicle_.tm_mon < _Src_Request.time_4_get_vehicle_.tm_mon ||
            this->time_4_get_vehicle_.tm_mday < _Src_Request.time_4_get_vehicle_.tm_mday ||
            this->time_4_get_vehicle_.tm_hour < _Src_Request.time_4_get_vehicle_.tm_hour ||
            this->time_4_get_vehicle_.tm_min < _Src_Request.time_4_get_vehicle_.tm_min ||
            this->time_4_get_vehicle_.tm_sec < _Src_Request.time_4_get_vehicle_.tm_sec;

        is_equal_adress_4_get_vehicle_ = this->adress_4_get_vehicle_ < _Src_Request.adress_4_get_vehicle_;
        is_equal_route_ = this->route_ < _Src_Request.route_;
        is_equal_category_vehicle_str_ = this->category_vehicle_str_ < _Src_Request.category_vehicle_str_;
        is_equal_passengers_numb_ = this->passengers_numb_ < _Src_Request.passengers_numb_;

        return is_equal_time_4_get_vehicle_ && is_equal_adress_4_get_vehicle_ && is_equal_route_ && is_equal_category_vehicle_str_ && is_equal_passengers_numb_;
    }


    int parseRequest(const std::string & str_str);
};

class TransporRequestsList {
public:
    std::vector<TransportRequestUnitFull> list_requests;
    int readFileWithTabDelim(const std::string & filename);

    TransporRequestsList() {
        this->list_requests.clear();
        this->list_requests.reserve(8000);
    }
    TransporRequestsList(const TransporRequestsList& _Src_Requests_List) {
        this->list_requests.clear();
        this->list_requests.reserve(_Src_Requests_List.list_requests.capacity());
        this->list_requests.resize(_Src_Requests_List.list_requests.size());
        this->list_requests.assign(_Src_Requests_List.list_requests.begin(), _Src_Requests_List.list_requests.end());
        //for (int it = 0; it < _Src_Requests_List.list_requests.size(); it++) {
        //    this->list_requests.at(it) = _Src_Requests_List.list_requests.at(it);
        //}
    }

    TransporRequestsList& operator=(const TransporRequestsList& _Src_Requests_List) 
    {
        if(this == &_Src_Requests_List)
            return *this;
        this->list_requests.clear();
        this->list_requests.reserve(_Src_Requests_List.list_requests.capacity());
        this->list_requests.assign(_Src_Requests_List.list_requests.begin(), _Src_Requests_List.list_requests.end());
        return *this;
    }


};


#endif //! H_TRANSPORT_REQUESTS